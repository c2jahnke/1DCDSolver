#ifndef PARAMETER_H
#define PARAMETER_H

class parameter
{
    double D; //diffusion coefficient
    double v; //velocity
    unsigned int nS; //number of species
    unsigned int nV; // number of Voxels
    unsigned int nT; //number of timesteps
    double lBc; //left boundary condtion
    double dx;
    double dt;

public:
    double L; // length
    parameter();
    parameter(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, unsigned nTsteps = 100, double leftBc = 1);
    // Setter methods
    void setLength(double Length)
    {
        L = Length;// length
    }
    // Getter methods
    double getLength()
    {
        return L;
    }
    double getDiff()
    {
        return D;
    }
    double getVel()
    {
        return v;
    }
    unsigned int getNumSpec()
    {
        return nS;
    }
    unsigned int getNumVox()
    {
        return nV;
    }
    unsigned int getNumTstep()
    {
        return nT;
    }

    double getLeftBc()
    {
        return lBc;
    }
    double getDx()
    {
        return dx;
    }
    double getDt()
    {
        return dt;
    }
    // Output
    void ParCout();
};

#endif // PARAMETER_H
