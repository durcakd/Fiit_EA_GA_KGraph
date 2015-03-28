#ifndef ALPHA_H
#define ALPHA_H


#include "util.h"
#include "math.h"

#include <vector>
#include <QDebug>
#include <bitset>

const double C = 0.01;

class Graph {

public:

    static void init(int sNodes);

    Graph();
    ~Graph();

    Graph *clone() const;
    int getFitness() const;


    bool calcFitness();
    void generate();
    void mutate();
    void crossover(const Graph &in2, Graph &out1, Graph &out2) const;

    QString toString() const;




private:


    static int _sNodes;

    double *_x;
    double *_y;
    int _fitnes;
};

#endif


