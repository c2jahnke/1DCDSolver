#include <iostream>
#include "cd1dinterface.h"
#include "cd1dparameter.h"
#include "cd1ddata.h"
#include "cd1dsolver.h"
#include <vector> // std::vector
#include <algorithm> //std::fill
int main()
{

    int nSpec = 3;
    std::vector<double> leftBc (nSpec);
    for(int k =0; k < nSpec; k++)
        leftBc[k]= k+1;
    // to have the same concentration on the inlet use:
    //std::fill (leftBc.begin(),leftBc.end(),1);
    for(int i = 0; i < nSpec; i++)
        std::cout << leftBc[i];
    std::cout << "\n";

    CD1DParameter Par = CD1DParameter(0.01 , 0,           nSpec,                10,             1, leftBc,              0); //dependence on the discretization
    // (double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length,std::vector<double> leftBc, unsigned nTsteps)
    Par.ParCout();

    CD1DData data;
    data.dataInit(& Par);
    data.dataCout();

    std::cout << "\n\n\n============== Starting solver: ==============\n";
    CD1DSolver sol2 = CD1DSolver(Par, data);
    std::cout << "Solving timestep...\n";
    bool outFlag = 1;
    std::cout << "\nSolving instationary\n";
    sol2.solveStationary(outFlag);
    // Why do we get a bug when cd1dinterface gets deallocated???
    CD1DInterface interface = CD1DInterface();
    //CD1DSolver sol = interface.getSolv(); // deep copy CD1DSolver(CD1DSolver mem) or delete this line
    std::cout <<"\n\n return 0;\n";
    return 0;
}

