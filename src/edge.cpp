#include "edge.h"

Edge::Edge(double x1,
           double y1,
           double x2,
           double y2,
           bool isIntercepted) {

    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->isIntercepted = isIntercepted;
}
