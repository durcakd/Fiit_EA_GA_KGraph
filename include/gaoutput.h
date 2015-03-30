#ifndef GAOUTPUT_H
#define GAOUTPUT_H

#include "graph.h"
#include <QVector>

class GAOutput
{

public:
    GAOutput();

    bool    oIsSolution;
    int     oResultFitness;
    int     oGenCall;
    int     oFitnessCall;


    // all tests
    double  tMeanFitness;
    double  tMeanFitnessCall;
    double  tMeanGenCall;
    int     tSolutions;
    Graph   *resGraph;

//    QVector<double> vfinalAlphaF;
//    QVector<double> vAlphaF;
//    QVector<double> testFitness;
//    QVector<double> testFitnessCalls;

};

#endif
