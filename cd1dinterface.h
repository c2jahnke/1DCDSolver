#ifndef CD1DINTERFACE_H
#define CD1DINTERFACE_H
#include "cd1dsolver.h"
#include "cd1ddata.h"
#include "cd1dparameter.h"
#include <vector>
/*class CD1CInterface
{
public:
    CD1DInterface();
};
*/
class Vector {
  friend class ConvDiffOperator;
public:// public methods
  Vector(int dim, double value);
  Vector(const Vector& other);
  const int dim;
  void scal(double val);
  void axpy(double a, const Vector& x);
  double dot(const Vector& other) const;
  double* data();
private:
  std::vector<double> _data;
};

class ConvDiffOperator{
public:
    ConvDiffOperator(double Diff, double vel, unsigned int nSpec, unsigned int nVox, double Length, unsigned nTsteps = 100, double leftBc = 1);
    CD1DData getTimestep();
    void setTimestep();
private:
    CD1DData data;
    CD1DParameter pars;
};

#endif // CD1DINTERFACE_H
