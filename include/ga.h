#ifndef GA_H
#define GA_H


#include "gainput.h"
#include "gaoutput.h"
#include "alpha.h"

//typedef unsigned int uint;

class GA
{

public:
    GA();

    GAOutput optimaze(const GAInput &in);


};

#endif


