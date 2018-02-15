#include <iostream>

#include "parameter.h"
#include "cd1ddata.h"
#include "cd1dsolver.h"

int main()
{
    parameter Par = parameter(0.1 , 0,           1,                12,             1,              19,              1); //dependence on the discretization

    // (double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, unsigned nTsteps, double leftBc)
    Par.ParCout();

    Cd1DData data;
    data.dataInit(& Par);
    data.dataCout();

    std::cout << "\n\n\n ============ Starting solver: ============\n\n";
    CD1DSolver sol2 = CD1DSolver(& Par, & data);
    std::cout << "Solving timestep...\n";
    bool outFlag = 0;
    sol2.solveProblem(outFlag);

    return 0;
}

