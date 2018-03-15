#ifndef CD1DDATA_H
#define CD1DDATA_H

#include <iostream>
#include <vector>
#include "cd1dparameter.h"

class CD1DData
{
    std::vector<std::vector<double> > conc;
    std::vector<std::vector<double> > concOld;
public:
    CD1DData();
    CD1DData(const CD1DData &data2);
    CD1DData(std::vector<std::vector<double> > c,std::vector<std::vector<double> > cOld);

    void dataInit(CD1DParameter * Par);
    // setter
    void setConcOld(std::vector<std::vector<double> > concNew) // set whole structure
    {
    if(concNew.size() != concOld.size())
        std::cerr << "Warning: concOld is changed in size!\n";
    concOld = concNew;
    }
    void setConc(std::vector<std::vector<double> > concNew)
    {
        if(concNew.size() != conc.size())
            std::cerr << "Warning: conc is changed in size!\n";
        conc = concNew;
    }

    void setConc(int s, std::vector<double> concSpez) //set species of conc
    {
        if(concSpez.size() != conc[s].size() )
            std::cerr << "Warning: conc[" << s <<"] is updated with new size " << concSpez.size() << "\n";

        conc[s] = concSpez;
    }
    void setConc(int x, int s, double val) //set value of conc
    {
        conc[s].at(x) = val;
    }
    void setConcOld(int x, int s, double val)
    {
        concOld[s].at(x) = val;
    }
    // getter methods
    std::vector<std::vector<double> > getConc() const
    {
        return conc;
    }
    std::vector<std::vector<double> > getConcOld() const
    {
        return concOld;
    }
    std::vector<double> getConc(int s) const // s species
    {
        return conc[s];
    }

    std::vector<double> getConcOld(int s) const
    {
        return concOld[s];
    }

    double getConc(int x, int s) const
    {
        return conc[s].at(x);
    }
    double getConcOld(int x, int s) const
    {
        return concOld[s].at(x);
    }

    void dataCout() const;
};

#endif // CD1DDATA_H
