#ifndef GA_H
#define GA_H


#include "hcinput.h"
#include "hcoutput.h"
#include "alpha.h"

//typedef unsigned int uint;

class GA
{

public:
    GA();

    HCOutput optimaze(const HCInput &in);
    void valuesTable(HCInput &in);

};

#endif


