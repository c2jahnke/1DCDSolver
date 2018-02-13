#ifndef CD1DDATA_H
#define CD1DDATA_H

#ifndef INCLUDE_VECT
#include <vector>
#endif //INCLUDE_VECT

class Cd1DData
{
    std::vector<std::vector<double>> conc;
    std::vector<std::vector<double>> concOld;
public:
    Cd1DData();
    Cd1DData(std::vector<std::vector<double>> c,std::vector<std::vector<double>> cOld);
};

#endif // CD1DDATA_H
