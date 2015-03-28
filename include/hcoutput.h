#ifndef HCOUTPUT_H
#define HCOUTPUT_H

#include "alpha.h"
#include <QVector>

class HCOutput
{

public:
    HCOutput();

    bool isSolution;
    double resultFitness;
    int tCount;
    int fitnessCount;

    double meanFitness;
    double meanFitnessCall;
    int solutions;

    QVector<double> vfinalAlphaF;
    QVector<double> vAlphaF;
    QVector<double> testFitness;
    QVector<double> testFitnessCalls;

};

#endif
