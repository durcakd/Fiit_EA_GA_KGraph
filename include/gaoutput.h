#ifndef GAOUTPUT_H
#define GAOUTPUT_H

#include "graph.h"
#include <QVector>

class GAOutput
{

public:
    GAOutput();

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
