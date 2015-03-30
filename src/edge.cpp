#include "edge.h"

Edge::Edge(QPoint node1,
           QPoint node2,
           bool isIntercepted) {

    this->node1 = node1;
    this->node2 = node2;
    this->isIntercepted = isIntercepted;
}
