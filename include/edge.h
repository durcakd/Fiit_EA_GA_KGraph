#ifndef EDGE_H
#define EDGE_H

#include <QDebug>
#include <QPoint>

class Edge
{
public:
    Edge(double x1,
         double y1,
         double x2,
         double y2,
         bool isIntercepted);

    double x1;
    double y1;
    double x2;
    double y2;
    bool isIntercepted;

};
#endif
