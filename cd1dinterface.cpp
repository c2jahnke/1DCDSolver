#include "cd1dinterface.h"
#include <assert.h>
#include <iostream>
#include <cmath>
/*CD1DInterface::CD1DInterface()
{

}
*/
//constructor for class Vector, copied from pymor example
Vector::Vector(int dim, double value) : _data(dim, value), dim(dim) {}

Vector::Vector(const Vector& other) : _data(other._data), dim(other.dim) {}

void Vector::scal(double val) {
  for (int i = 0; i < dim; i++) {
    _data[i] *= val;
  }
}

void Vector::axpy(double a, const Vector& x) {
  assert(x.dim == dim);
  for (int i = 0; i < dim; i++) {
    _data[i] += a * x._data[i];
  }
}

double Vector::dot(const Vector& other) const {
  assert(other.dim == dim);
  double result = 0;
  for (int i = 0; i < dim; i++) {
    result += _data[i] * other._data[i];
  }
  return result;
}

double* Vector::data() {
  return _data.data();
}

