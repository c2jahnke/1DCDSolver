#ifndef PARAMETER_H
#define PARAMETER_H

class parameter
{
    double D; //diffusion coefficient
    double v; //velocity
    unsigned int nS; //number of species
    unsigned int nV; // number of Voxels

public:
    double L; // length
    parameter();
    parameter(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length);
    void setLength(double Length);
    double getLength();
    void ParCout();
};

#endif // PARAMETER_H
