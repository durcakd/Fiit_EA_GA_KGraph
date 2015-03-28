#include "graph.h"
#include "util.h"

//// define static fields and methods
int Graph::_sNodes;

void Graph::init(int sNodes) {
    _sNodes = sNodes;
}


//-- constructor
Graph::Graph() {
    _fitnes = -1;
    _x = new double[_sNodes];
    _y = new double[_sNodes];
}

//-- destructor
Graph::~Graph() {
    delete _x;
    delete _y;
}

//-- clone
Graph *Graph::clone() const {
    Graph *cloned = new Graph;


    return cloned;
}

//-- to String
QString Graph::toString() const {
    QString s = "F= " + QString::number(getFitness());
    return s;
}

//-- get fitness
int Graph::getFitness() const {
    return _fitnes;
}

// calc fitness
bool Graph::calcFitness() {
    return true;
}

//-- generate
void Graph::generate() {

}

//-- mutate
void Graph::mutate() {

}

// crossover
void Graph::crossover(const Graph &in2, Graph &out1, Graph &out2) const {

}

