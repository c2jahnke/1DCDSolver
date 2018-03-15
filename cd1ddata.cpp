#include "cd1ddata.h"

#include <iostream>
#include <vector>

#include "cd1dparameter.h"

CD1DData::CD1DData()
{

}
CD1DData::CD1DData(std::vector<std::vector<double> > c,std::vector<std::vector<double> > cOld){
    conc = c;
    concOld = cOld;
}
CD1DData::CD1DData(const CD1DData &data2){
    conc = data2.getConc();
    concOld = data2.getConcOld();
}

void CD1DData::dataInit(CD1DParameter * Par)
{
    concOld.resize(Par->getNumSpec());
    for (unsigned int k = 0 ; k < concOld.size(); k++)
        concOld[k].resize(Par->getNumVox());
    conc = concOld;
}


void CD1DData::dataCout() const
{
    std::cout << "data.concOld = \n";
    for (unsigned int k = 0; k< concOld.size(); k++)
    {
        for(unsigned int j = 0; j < concOld[k].size(); j++)
        {
            std::cout << concOld[k][j] << " ";
        }
        std::cout << "     \n";
    }
    std::cout << "\n";
    std::cout << "data.conc = \n";
    for (unsigned int k = 0; k< conc.size(); k++)
    {
        for(unsigned int j = 0; j < conc[k].size(); j++)
        {
            std::cout << conc[k][j] << " ";
        }
        std::cout << "     \n";
    }
}
