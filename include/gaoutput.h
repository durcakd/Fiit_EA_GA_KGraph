#ifndef GAOUTPUT_H
#define GAOUTPUT_H

#include "graph.h"
#include <QVector>

class GAOutput
{

public:
    GAOutput();

    QString testOutToString() const;

    bool    oIsSolution;
    int     oResultFitness;
    int     oGenCall;
    int     oFitnessCall;

    // all tests
    Graph   *resGraph;
    int     tSolutions;
    double  tSuccess;

    double  tMeanFitness;
    double  tMeanFitnessCall;
    double  tMeanGenCall;
    double  tSoFitness;
    double  tSoFitnessCall;
    double  tSoGenCall;

};

#endif
