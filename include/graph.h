#ifndef ALPHA_H
#define ALPHA_H


#include "util.h"
#include "math.h"

#include <vector>
#include <QDebug>
#include <map>
#include <string>


class Graph {

public:

    static void init(int sNodes);

    Graph();
    ~Graph();

    Graph *clone() const;
    void setNodes(const double *x, const double *y, int fitness);
    void setNodes(const double *x, const double *y, int start, int end);
    inline const double *x() const {return _x;}
    inline const double *y() const {return _y;}
    int getFitness() const;


    int calcFitness();
    void generateNodes();
    void probabilityMutate(double probability);
    void mutate();
    void crossover(const Graph &in2, Graph &out1, Graph &out2) const;

    QString toString() const;
    void getExtremNodesCords(double &minx, double &miny, double &maxx, double &maxy) const;

    std::map<std::string, bool> *getEdges();


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

    void addEdgeToMap(int n1, int n2, bool isIntercept);
    void calculateEdges();

    static int _sNodes;

    double *_x;
    double *_y;
    int _fitnes;

    bool createEdges;
    std::map<std::string, bool> *edges;


};


#endif


