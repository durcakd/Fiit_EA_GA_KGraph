#ifndef EDGE_H
#define EDGE_H

#include <QDebug>
#include <QPoint>

class Edge
{
public:
    Edge(QPoint node1,
         QPoint node2,
         bool isIntercepted);

    QPoint node1;
    QPoint node2;
    bool isIntercepted;

};
#endif
