#ifndef CD1DSOLVER_H
#define CD1DSOLVER_H

#include "cd1ddata.h"
#include "cd1dparameter.h"
#include <vector>
#include <armadillo>

class CD1DSolver
{
    std::vector<double> time;
    bool timeDep; // 0 stationary, 1 instationary
    bool alloz; // 1 allocated memory, 0 external pointers used
    std::vector<arma::mat> A;
    CD1DParameter * par;
    CD1DData * dat;


public:
    CD1DSolver ();
    ~CD1DSolver();
    CD1DSolver(CD1DParameter param, CD1DData data);
    // CD1DSolver(const CD1DSolver &solv2); // copy constructor
    CD1DSolver(CD1DParameter * param);
    CD1DSolver(CD1DParameter * param, CD1DData * data);
    void solveInstationary(bool outFlag);
    void solveTimestep(bool outFlag);
    void solveStationary(bool outFlag);
    void assemble();

};

#endif // CD1DSOLVER_H
