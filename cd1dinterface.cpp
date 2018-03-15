#include "cd1dinterface.h"
#include <assert.h>
#include <iostream>
#include <cmath>
#include "cd1dparameter.h" // for ConvDiffOperator
#include "cd1ddata.h"
#include "cd1dsolver.h"
#include <vector>

CD1DInterface::CD1DInterface()
{

    //no segmentation fault, deep copy
    std::vector<double> leftBc;
    leftBc.assign (1,1);
    CD1DParameter pars = CD1DParameter(0.01 , 0,           1,                10,             1, leftBc ,              0);
    CD1DData data;
    data.dataInit(& pars);
    solv = CD1DSolver(pars, data);
    std::cout << "Interface solver created.\n";

}

CD1DInterface::CD1DInterface(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, std::vector<double> leftBc, unsigned int nTsteps)
{
    CD1DParameter pars = CD1DParameter(Diff,vel, nSpec, nVox, Length, leftBc, nTsteps);
    CD1DData data;
    data.dataInit(& pars);
    solv = CD1DSolver(pars, data);
}
CD1DInterface::CD1DInterface(std::string XmlInputPath){

}

//void CD1DInterface::apply(const Vector& U, Vector& R){}
void CD1DInterface::solveStationary(){


}

