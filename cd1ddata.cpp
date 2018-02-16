#include "cd1ddata.h"

#include <iostream>
#include <vector>

#include "cd1dparameter.h"



Cd1DData::Cd1DData()
{

}
Cd1DData::Cd1DData(std::vector<std::vector<double>> c,std::vector<std::vector<double>> cOld){
    conc = c;
    concOld = cOld;
}
void Cd1DData::dataInit(cd1dparameter * Par)
{
    concOld.resize(Par->getNumSpec());
    for ( int k = 0 ; k < concOld.size(); k++)
        concOld[k].resize(Par->getNumVox());
    conc = concOld;
   }

void Cd1DData::dataCout()
{
    std::cout << "data.concOld = \n";
    for (int k = 0; k< concOld.size(); k++)
    {
        for(int j = 0; j < concOld[k].size(); j++)
        {
            std::cout << concOld[k][j] << " ";
        }
        std::cout << "     \n";
    }
    std::cout << "\n";
    std::cout << "data.conc = \n";
    for (int k = 0; k< conc.size(); k++)
    {
        for(int j = 0; j < conc[k].size(); j++)
        {
            std::cout << conc[k][j] << " ";
        }
        std::cout << "     \n";
    }



}
