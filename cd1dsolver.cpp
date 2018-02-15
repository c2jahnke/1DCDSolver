#include "cd1dsolver.h"



#include <armadillo>
#include <vector>
#include "cd1ddata.h"
#include "parameter.h"


CD1DSolver::CD1DSolver()
{


}
CD1DSolver::CD1DSolver(parameter * param)
{
       par = param;
}

CD1DSolver::CD1DSolver(parameter *param, Cd1DData * data)
{
       par = param;
       dat = data;
}

void CD1DSolver::solveProblem(bool outFlag)
{
    for(int k=0; k != par->getNumTstep(); k++)
    {
        std::cout <<  "============== timestep = " << k << ", time = " << par->getDt()*k << " ==============\n";
        if(outFlag == 0 && k == (par->getNumTstep()-1))
        {
            this->solveTimestep(1);
        }
        else
        {
            this->solveTimestep(outFlag);
        }
    }
}
void CD1DSolver::solveTimestep(bool outFlag)
{
    dat->setConcOld(dat->getConc()); // copy Conc to ConcOld
    if(outFlag)
    {
        std::cout << "\n Number of species: " << dat->getConc().size() << "\n\n";
        // dat->dataCout();
    }
    for (unsigned int s = 0; s< dat->getConc().size(); s++) // loop over species
    {
        std:: cout << "============== s = " << s << " ==============\n\n";

        // Matrix assembly
        // assembly in separate function, but left boundary have to be inserted into rhs

        arma::mat matA(par->getNumVox(),par->getNumVox(),arma::fill::zeros);

        double h = par->getDx();
        double dt = par->getDt();
        std::cout << "h = " << h << "\ndt = " << dt << "\n";
        // set left boundary
        matA(0,0) = (1+6*par->getDiff()/(h*h)*dt+2*par->getVel()/h*dt);
        matA(0,1) = -2*par->getDiff()/(h*h)*dt;
        // put lBc to rhs
        dat->setConcOld(0,s,dat->getConcOld(0,s)+ par->getLeftBc()*(4*par->getDiff()/(h*h)*dt+2*par->getVel()/h*dt));

        std::cout << "left boundary set.\n";
        // set right boundary
        matA(par->getNumVox()-1,par->getNumVox()-1) = (1+2*par->getDiff()/(h*h)*dt + par->getVel()/h*dt);
        matA(par->getNumVox()-1,par->getNumVox()-2) = -(2*par->getDiff()/(h*h)*dt + par->getVel()/h*dt);
        std::cout << "right boundary set.\n";

        for(int j=1; j < par->getNumVox()-1;j++)
        {
            matA(j,j) = 1+2*par->getDiff()/(h*h)*dt +par->getVel()/h*dt;
            matA(j,j-1) = - par->getDiff()/(h*h)*dt - par->getVel()/h*dt;
            matA(j,j+1) = - par->getDiff()/(h*h)*dt;
        }

        // Matrix output
        if(outFlag){
        std::cout << "\n A = \n";
        for(int j = 0; j < par->getNumVox(); j++)
        {
            for (int k = 0; k < par->getNumVox(); k++)
            {
                std::cout << matA(j,k) << " ";
            }
            std::cout << "\n";
        }
        }
        // initialize armadillo mat with std::vector
        std::vector<double> b = dat->getConcOld(s);
        arma::vec b1 = arma::vec(b);

        //solve system
        arma::vec sol = arma::solve(matA,b1);

        std::vector<double> solVec = arma::conv_to<std::vector<double> >::from(sol.col(0));
        dat->setConc(s,solVec);
        dat->dataCout();
    }
}
