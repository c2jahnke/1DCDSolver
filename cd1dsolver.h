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
    CD1DParameter * par;
    CD1DData * dat;
public:
    CD1DSolver();
    CD1DSolver(CD1DParameter * param);
    CD1DSolver(CD1DParameter * param, CD1DData * data);
    void solveProblem(bool outFlag);
    void solveTimestep(bool outFlag);
    void solveStationary(std::vector<double> U);

};

#endif // CD1DSOLVER_H
