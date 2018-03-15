
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
    lBc.assign (this->nS,1);
    dx = this->L/this->nV; // voxelsize
    dt = 1/this->nT; // timestep
}

CD1DParameter::CD1DParameter(const CD1DParameter & param2)
{
    D = param2.getDiff();
    v = param2.getVel();
    nS = param2.getNumSpec();
    nV = param2.getNumVox();
    L = param2.getLength();
    nT = param2.getNumTstep();
    lBc = param2.getLeftBc();
    dx = param2.getDx();
    dt = param2.getDt();
}

CD1DParameter::CD1DParameter(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, std::vector<double> leftBc, unsigned nTsteps)
{
    D = Diff;
    v = vel;
    nS = nSpec;
    nV = nVox;
    L = Length;
    nT = nTsteps;
    // std::cout << "============== number of timesteps nT = " << nT << " ==============\n";
    /*if(leftBc.size() != nSpec){
        cerr << "The size of the left boundary vector is not equal to the number of species.";
    }*/
    if(leftBc.size() != this->nS)
        std::cerr << "Concentration vector at inlet of size: " << leftBc.size() << " while it is suposed to be of size " << this->nS << ".\n Results might be incorrect.\n\n";
    lBc = leftBc;
    dx = Length/nVox; // voxelsize
    dt = 10.0/nTsteps; // timestep
}
void CD1DParameter::ParCout() const
{
    std::cout << "==============\n" << "Paramter class with:\n";
    std::cout << "Diffusion D = " << D << "\nVelocity v = " << v << "\nNumber of Species nS = " << nS << "\nNumber of Voxels nV = "<< nV;
    std::cout  << "\nLength L = " << L << "\nNumber of timesteps nT = " << nT << "\nVoxel size dx = " << dx << "\nTime step dt = " << dt << "\n" << "==============\n";
}

