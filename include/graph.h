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
    void setNodes(const double *x, const double *y, int fitness);
    int getFitness() const;


    bool calcFitness();
    void generateNodes();
    void mutate();
    void crossover(const Graph &in2, Graph &out1, Graph &out2) const;

    QString toString() const;




private:

    void edgeBacktrack(int start);
    void edgeBacktrack(int start, int its);
    void edgeBacktrack(int start, int its, double x1, double y1, double x2, double y2);
    bool interfereEdges(double x1, double y1, double x2, double y2,
                        double x3, double y3, double x4, double y4);

    static int _sNodes;

    double *_x;
    double *_y;
    int _fitnes;
};

#endif


