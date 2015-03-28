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
            //bool isInterference = interfereEdges(_x[start], _y[start], _x[i], _y[i]);
            qDebug() << start<<" x "<< i;
            //edgeBacktrack(start, i+1);
            edgeBacktrack(start, i+1,
                          _x[start], _y[start], _x[i], _y[i]);

        }
        edgeBacktrack(start+1);
    }
}

void Graph::edgeBacktrack(int start, int its) {
    if (start+1 < _sNodes) {
        for (int i=its ; i<_sNodes; i++) {
            qDebug() <<"   "<<  start<<" x "<< i;
        }
        edgeBacktrack(start+1, start+2);
    }
}

void Graph::edgeBacktrack(int start, int its,
                          double x1, double y1, double x2, double y2) {

    if (start+1 < _sNodes) {
        for (int i=its ; i<_sNodes; i++) {

            bool interfer = interfereEdges(x1, y1, x2, y2,
                                           _x[start], _y[start], _x[i], _y[i]);
            _fitnes += interfer ? 1 : 0;
            qDebug() <<"   "<<  start<<" x "<< i << "  " << interfer;
        }
        edgeBacktrack(start+1, start+2, x1, y1, x2, y2);
    }
}

bool Graph::interfereEdges(double x1, double y1, double x2, double y2,
                double x3, double y3, double x4, double y4) {
    if (x1 > x2) {
        if (x3 > x4) {
            return interfereOrderedEdges(x2,y2,x1,y1, x4,y4,x3,y3);
        } else {
            return interfereOrderedEdges(x2,y2,x1,y1, x3,y3,x4,y4);
        }
    } else {
        if (x3 > x4) {
            return interfereOrderedEdges(x1,y1,x2,y2, x4,y4,x3,y3);
        } else {
            return interfereOrderedEdges(x1,y1,x2,y2, x3,y3,x4,y4);
        }
    }
}

bool Graph::interfereOrderedEdges(double x1, double y1, double x2, double y2,
                                  double x3, double y3, double x4, double y4) {
    // must be true that x1<=x2 && x3<=x4

    if (0.0==x2-x1 || 0.0==x4-x3) {
        qDebug() << "Huston we have a problem";
    }

    // slopes (smernice)
    double a1 = (y2-y1)/(x2-x1);
    double a2 = (y4-y3)/(x4-x3);

    // TODO if (a1-a2)

    double da = a1-a2;
    if (0.0 != da) {
        // priesecnik (suradnica x)
        double x = (a1*x1 -y1 -a2*x3 +y3)/(da);

    } else {

    }





    return true;
}




//-- mutate --
void Graph::mutate() {

}

//-- crossover --
void Graph::crossover(const Graph &in2, Graph &out1, Graph &out2) const {

}

