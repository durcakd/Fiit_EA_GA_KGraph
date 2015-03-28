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
    void edgeBacktrack(int start, int its,
                       double x1, double y1, double x2, double y2,
                       int node1, int node2);
    bool interceptEdges(double x1, double y1, double x2, double y2,
                        double x3, double y3, double x4, double y4, bool hasSameNodes) const;
    bool interceptOrderedEdges(double x1, double y1, double x2, double y2,
                               double x3, double y3, double x4, double y4, bool hasSameNodes) const;
    bool interceptOrderedEdges1(double x1, double y1, double x2, double y2,
                               double x3, double y3, double x4, double y4, bool hasSameNodes) const;
    bool interceptOrderedEdges2(double x1, double y1, double x2, double y2,
                               double x3, double y3, double x4, double y4, bool hasSameNodes) const;
    bool checkSameNodes(int i1, int i2, int i3, int i4) const;

    bool checkSameNodesValues(double x, double y, int index) const;

    static int _sNodes;

    double *_x;
    double *_y;
    int _fitnes;
};

#endif


