#include "ga.h"

#include <math.h>
#include <vector>

#include <QDebug>
#include "util.h"

GA::GA()
{
}



GAOutput GA::optimaze(const GAInput &in)
{
    GAOutput out;
    out.isSolution = false;
    out.resultFitness = 1.0;
    //out.tCount = in.tmax;
    out.fitnessCount = 0;


}

