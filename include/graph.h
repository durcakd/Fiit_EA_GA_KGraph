#ifndef ALPHA_H
#define ALPHA_H


#include "util.h"
#include "math.h"

#include <vector>
#include <QDebug>
#include <map>
#include <string>
#include <edge.h>


class Graph {

public:

    static void init(int sNodes);
    static bool hasSolution(int nodesCount);


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

    // painting
    void calculateEdges(std::vector<Edge*> &edgeList);

    // solutions
    bool isSolution() const;

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
    std::map<std::string, Edge*> *getEdges();

    static int _sNodes;
    static int _solutionCount;
    const int solutions[18];

    double *_x;
    double *_y;
    int _fitnes;

    bool createEdges;
    std::map<std::string, Edge*> *edges;


};


#endif

/*
0   0
1   0
2   0
3	0
4	0
5	1
6	3
7	9
8	19
9	36
10	62
11	102
12	153
13	229
14	324
15	447
16	603
17	798
18	1029
19	1318
20	[1652,1657]
21	2055
22	[2521,2528]
23	[3075,3077]
24	[3690,3699]
25	[4426,4430]
*/

