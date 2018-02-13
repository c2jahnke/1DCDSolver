//#pragma once
//#ifndef PARAMETER_H
//#define PARAMETER_H
#include "parameter.h"
//#endif

#ifndef INCLUDED_IO
#include <iostream>
#endif

parameter::parameter()
{
}
void parameter::setLength(double Length)
{
    L = Length;// length
}
double parameter::getLength(){
    return L;
}
parameter::parameter(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length){
    D = Diff;
    v = vel;
    nS = nSpec;
    nV = nVox;
    L = Length;
}
void parameter::ParCout(){
    std::cout << "Paramter class given by:\n";
    std::cout << "Diffusion D = " << D << "\nVelocity v = " << v << "\nNumber of Species nS = " << nS << "\nNumber of Voxels nV = " << nV << "\nLength L = " << L << "\n";
}

