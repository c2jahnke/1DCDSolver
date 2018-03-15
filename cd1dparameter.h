#ifndef CD1DPARAMETER_H
#define CD1DPARAMETER_H
#include <vector>

class CD1DParameter
{
    double D; //diffusion coefficient
    double v; //velocity
    unsigned int nS; //number of species
    unsigned int nV; // number of Voxels
    unsigned int nT; //number of timesteps
    std::vector<double> lBc; //left boundary condtion
    double dx;
    double dt;

public:
    double L; // length
    CD1DParameter();
    //deep copy constructor
    CD1DParameter(const CD1DParameter &param2);
    CD1DParameter(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, std::vector<double> leftBc, unsigned nTsteps = 100);
    // Setter methods
    void setLength(double Length)
    {
        L = Length;// length
    }
    // Getter methods
    double getLength() const
    {
        return L;
    }
    double getDiff() const
    {
        return D;
    }
    double getVel() const
    {
        return v;
    }
    unsigned int getNumSpec() const
    {
        return nS;
    }
    unsigned int getNumVox() const
    {
        return nV;
    }
    unsigned int getNumTstep() const
    {
        return nT;
    }

    std::vector<double> getLeftBc() const
    {
        return lBc;
    }
    double getDx() const
    {
        return dx;
    }
    double getDt() const
    {
        return dt;
    }
    // Output
    void ParCout() const;
};

#endif // CD1DPARAMETER_H
