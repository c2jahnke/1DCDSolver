#include "cd1dsolver.h"
#include <armadillo> //take care of linking
#include <vector>
#include "cd1ddata.h"
#include "cd1dparameter.h"
#include "assert.h"

CD1DSolver::CD1DSolver()
{


}
CD1DSolver::CD1DSolver(CD1DParameter param, CD1DData data)
{
    alloz = 1;
    std::cout << "Data allocation\n";
    par = new CD1DParameter(param);
    dat = new CD1DData(data);
    A.resize(par->getNumSpec());
    if (par->getNumTstep() > 0)
    {
        timeDep = 1;
    }
        else
    {
        timeDep = 0;
    }
}

CD1DSolver::CD1DSolver(CD1DParameter * param)
{
    alloz = 0;
     par = param;
     A.resize(par->getNumSpec());
     if (par->getNumTstep() > 0)
     {
         timeDep = 1;
     }
     else
     {
         timeDep = 0;
     }
}

CD1DSolver::CD1DSolver(CD1DParameter *param, CD1DData * data)
{
    alloz = 0;

    par = param;
    dat = data;
    A.resize(par->getNumSpec());
    if (par->getNumTstep() > 0)
    {
        timeDep = 1;
    }
        else
    {
        timeDep = 0;
    }
}
CD1DSolver::~CD1DSolver(){

    if(alloz)
    {
        std::cout << "alloz = " << alloz;
        std::cout << "\nCD1DSolver: Calling delete\n";
        std::cout << "par " << par  <<"\n";
        std::cout << "dat " << dat << "\n";
        delete par;
        delete dat;
    }

}
/*
CD1DSolver::CD1DSolver(const CD1DSolver &solv2)
{



}
*/
void CD1DSolver::assemble(){
    std::cout << "Hello\n";
    std::cout << dat->getConc().size(); // why does this call provoke a bad_alloc?
    if(timeDep == 0) //stationary assembly
    {

        for (unsigned int s = 0; s < dat->getConc().size(); s++) // loop over species
        {

            // Matrix assembly
            // assembly in separate function, but left boundary have to be inserted into rhs

            arma::mat matA(par->getNumVox(),par->getNumVox(),arma::fill::zeros);

            double h = par->getDx();
            std::cout << "h = " << h << "\n";
            // set left boundary
            matA(0,0) = (6*par->getDiff()/(h*h)+2*par->getVel()/h);
            matA(0,1) = -2*par->getDiff()/(h*h);
            dat->setConcOld(0,s,dat->getConcOld(0,s)+ par->getLeftBc()[s]*(4*par->getDiff()/(h*h)+2*par->getVel()/h));
            std::cout << "left boundary set.\n";

            // set right boundary
            matA(par->getNumVox()-1,par->getNumVox()-1) = (2*par->getDiff()/(h*h) + par->getVel()/h);
            matA(par->getNumVox()-1,par->getNumVox()-2) = - (2*par->getDiff()/(h*h) + par->getVel()/h);
            std::cout << "right boundary set.\n";
            dat->dataCout();
            //write discretization scheme!
            for(unsigned int j=1; j < par->getNumVox()-1;j++)
            {
                matA(j,j) =  2*par->getDiff()/(h*h) +par->getVel()/h;
                matA(j,j-1) = -par->getDiff()/(h*h) + par->getVel()/h;
                matA(j,j+1) = -par->getDiff()/(h*h);
            }
            A[s] = matA; // save assembled operator
        }

    }
    else // instationary case
    {
        for (unsigned int s = 0; s< dat->getConc().size(); s++) // loop over species
        {
           // Matrix assembly
            // assembly in separate function, but left boundary have to be inserted into rhs

            arma::mat matA(par->getNumVox(),par->getNumVox(),arma::fill::zeros);

            double h = par->getDx();
            double dt = par->getDt();
            std::cout << "h = " << h << "\ndt = " << dt << "\n";
            // set left boundary
            matA(0,0) = (1+6*par->getDiff()/(h*h)*dt+2*par->getVel()/h*dt);
            matA(0,1) = -2*par->getDiff()/(h*h)*dt;
            // put lBc to rhs // write getLeftBc(s)
            dat->setConcOld(0,s,dat->getConcOld(0,s)+ par->getLeftBc()[s]*(4*par->getDiff()/(h*h)*dt+2*par->getVel()/h*dt));

            std::cout << "left boundary set.\n";
            // set right boundary
            matA(par->getNumVox()-1,par->getNumVox()-1) = (1+2*par->getDiff()/(h*h)*dt + par->getVel()/h*dt);
            matA(par->getNumVox()-1,par->getNumVox()-2) = -(2*par->getDiff()/(h*h)*dt + par->getVel()/h*dt);
            std::cout << "right boundary set.\n";

            for(unsigned int j=1; j < par->getNumVox()-1;j++)
            {
                matA(j,j) = 1+2*par->getDiff()/(h*h)*dt +par->getVel()/h*dt;
                matA(j,j-1) = - par->getDiff()/(h*h)*dt - par->getVel()/h*dt;
                matA(j,j+1) = - par->getDiff()/(h*h)*dt;
            }
        A[s] = matA; //save assembled operator
        }
    }
}
void CD1DSolver::solveStationary(bool outFlag){
    if(timeDep != 0)
        std::cerr << "Set timesteps nT to zero in order to obtain a stationary solution.\n";
    std::cout <<  "============== Stationary solver ==============\n";
    this->assemble();
    std::cout << "\ntimeDep: " << timeDep << "\n";
    for (unsigned int s = 0; s< dat->getConc().size(); s++) // loop over species
    {
        std:: cout << "============== s = " << s << " ==============\n";
        arma::mat matA = A[s];
        // Matrix output
        if(outFlag){
        std::cout << "\nA = \n";
        for(unsigned int j = 0; j < par->getNumVox(); j++)
        {
            for (unsigned int k = 0; k < par->getNumVox(); k++)
            {
                std::cout << matA(j,k) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
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


void CD1DSolver::solveInstationary(bool outFlag) // Instationary Solver
{
    for(unsigned int k=0; k != par->getNumTstep(); k++)
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
    this->assemble();
    for (unsigned int s = 0; s< dat->getConc().size(); s++) // loop over species
    {
        std:: cout << "============== s = " << s << " ==============\n";

        arma::mat matA = A[s];
        // Matrix output
        if(outFlag){
        std::cout << "\n A = \n";
        for(unsigned int j = 0; j < par->getNumVox(); j++)
        {
            for (unsigned int k = 0; k < par->getNumVox(); k++)
            {
                std::cout << matA(j,k) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
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
