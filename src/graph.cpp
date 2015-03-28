#include "graph.h"
#include "util.h"

//// define static fields and methods
int Graph::_sNodes;

void Graph::init(int sNodes) {
    _sNodes = sNodes;
}


//-- constructor --
Graph::Graph() {
    _fitnes = -1;
    _x = new double[_sNodes];
    _y = new double[_sNodes];
}

//-- destructor --
Graph::~Graph() {
    delete _x;
    delete _y;
}

//-- generate --
void Graph::generateNodes() {
    _fitnes = -1;
    for (int i=0; i<_sNodes; i++) {
        _x[i] = Util::get()->ud();
        _y[i] = Util::get()->ud();
    }
}

//-- clone --
Graph *Graph::clone() const {
    Graph *cloned = new Graph;
    cloned->setNodes(_x, _y, _fitnes);
    return cloned;
}

//-- setNodes --
void Graph::setNodes(const double *x, const double *y, int fitness) {
    _fitnes = fitness;
    for (int i=0; i<_sNodes; i++) {
        _x[i] = x[i];
        _y[i] = y[i];

    }
}

//-- to String --
QString Graph::toString() const {
    QString s = "F= " + QString::number(getFitness());

    for (int i=0; i<_sNodes; i++) {
        s += " ("+QString::number(_x[i])+" "+QString::number(_y[i])+")";
    }
    return s;
}
// --------- fitnes ----------------------------
//-- get fitness --
int Graph::getFitness() const {
    return _fitnes;
}

// calc fitness --
bool Graph::calcFitness() {
    if (-1 == _fitnes) {
        _fitnes = 0;
        edgeBacktrack(0);
        return true;
    }
    return false;
}

void Graph::edgeBacktrack(int start) {
    if (start+1 < _sNodes) {
        for (int i=start+1 ; i<_sNodes; i++) {
            bool isInterference = interfereEdges(_x[start], _y[start], _x[i], _y[i]);
            qDebug() << start<<" x "<< i << "  " << isInterference;
            _fitnes += isInterference ? 1 : 0;
        }
        edgeBacktrack(start+1);
    }
}

bool Graph::interfereEdges(double x1, double y1, double x2, double y2) {









    return true;
}




//-- mutate --
void Graph::mutate() {

}

//-- crossover --
void Graph::crossover(const Graph &in2, Graph &out1, Graph &out2) const {

}

