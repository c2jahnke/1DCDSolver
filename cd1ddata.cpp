#include "cd1ddata.h"

Cd1DData::Cd1DData()
{

}
Cd1DData::Cd1DData(std::vector<std::vector<double>> c,std::vector<std::vector<double>> cOld){
    conc = c;
    concOld = cOld;
}
