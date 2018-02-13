
#ifndef INCLUDED_IO
#include <iostream>
#endif

//#ifndef PARAMETER_H
//#define PARAMETER_H
#include "parameter.h"
//#endif
#include "cd1ddata.h"


int main()
{
    parameter Par = parameter(1,0,1,12,1);
    Par.setLength(3);
    std::cout <<"Parameter.length = "<<  Par.getLength() << std::endl;
    Par.ParCout();
    Cd1DData data;

    return 0;
}

