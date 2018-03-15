#ifndef CD1DINTERFACE_H
#define CD1DINTERFACE_H
#include "cd1dsolver.h"
#include "cd1ddata.h"
#include "cd1dparameter.h"
#include <vector>

class CD1DInterface
{
    CD1DSolver solv;
public:
    CD1DInterface();
//    const int dim_source;
//    const int dim_range;
    ~CD1DInterface()
    {
        std::cout << "CD1DInterface: Calling destructor\n";
        solv.~CD1DSolver();
    }
    CD1DInterface(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, std::vector<double> leftBc, unsigned int nTsteps);
    CD1DInterface(std::string XmlInputPath);
//    void apply(const Vector& U, Vector& R) const;
    void solveStationary();
    CD1DSolver getSolv()
    {
        return solv;
    }
};
#endif // CD1DINTERFACE_H
