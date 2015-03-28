#ifndef GA_H
#define GA_H


#include "gainput.h"
#include "gaoutput.h"
#include "graph.h"

class GA
{

public:
    GA();

    GAOutput optimaze(const GAInput &in);


};

#endif


