#ifndef CD1DSOLVER_H
#define CD1DSOLVER_H

#include "cd1ddata.h"
#include "parameter.h"
#include <vector>
#include <armadillo>

class CD1DSolver
{
    std::vector<double> time;
    //unsigned nT; //number of timesteps
    arma::mat A;
    parameter * par;
    Cd1DData * dat;
public:
    CD1DSolver();
    CD1DSolver(parameter * param);
    CD1DSolver(parameter * param, Cd1DData * data);
    void solveProblem(bool outFlag);
    void solveTimestep(bool outFlag);

};

#endif // CD1DSOLVER_H
