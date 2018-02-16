#ifndef CD1DSOLVER_H
#define CD1DSOLVER_H

#include "cd1ddata.h"
#include "cd1dparameter.h"
#include <vector>
#include <armadillo>

class CD1DSolver
{
    std::vector<double> time;
    //unsigned nT; //number of timesteps
    arma::mat A;
    cd1dparameter * par;
    Cd1DData * dat;
public:
    CD1DSolver();
    CD1DSolver(cd1dparameter * param);
    CD1DSolver(cd1dparameter * param, Cd1DData * data);
    void solveProblem(bool outFlag);
    void solveTimestep(bool outFlag);

};

#endif // CD1DSOLVER_H
