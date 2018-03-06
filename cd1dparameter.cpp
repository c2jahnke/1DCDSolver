
#include "cd1dparameter.h"

#include <iostream>

CD1DParameter::CD1DParameter()
{
    D = 1;
    v = 0;
    nS = 1;
    nV = 10;
    L = 1;
    nT = 100;
    lBc = 1;
    dx = this->L/this->nV; // voxelsize
    dt = 1/this->nT; // timestep
}

CD1DParameter::CD1DParameter(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, unsigned nTsteps, double leftBc)
{
    D = Diff;
    v = vel;
    nS = nSpec;
    nV = nVox;
    L = Length;
    nT = nTsteps;
    std::cout << "================number of timesteps\n\n\n\n\n" << nT << "                         \n\n\n ================";
    lBc = leftBc;
    dx = Length/nVox; // voxelsize
    dt = 10.0/nTsteps; // timestep
}
void CD1DParameter::ParCout()
{
    std::cout << "Paramter class with:\n";
    std::cout << "Diffusion D = " << D << "\nVelocity v = " << v << "\nNumber of Species nS = " << nS << "\nNumber of Voxels nV = "<< nV;
    std::cout  << "\nLength L = " << L << "\nNumber of timesteps nT = " << nT << "\nVoxel size dx = " << dx << "\nTime step dt = " << dt << "\n";
}

