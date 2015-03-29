#include "graph.h"
#include "util.h"

//// define static fields and methods
int Graph::_sNodes;

void Graph::init(int sNodes) {
    if (sNodes<3) {
        sNodes = 3;
    }
    _sNodes = sNodes;

    Util::get()->setIntDistUpBound(sNodes);
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
        _x[i] = Util::get()->udD();
        _y[i] = Util::get()->udD();
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

void Graph::setNodes(const double *x, const double *y, int start, int end) {
    if (end > _sNodes) {
        end = _sNodes;
    }
    if (start < 0) {
        start = 0;
    }
    for (int i=start; i<end; i++) {
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
int Graph::calcFitness() {
    if (-1 == _fitnes) {
        _fitnes = 0;
        edgeBacktrack(0);
        return 1;
    }
    return 0;
}

void Graph::edgeBacktrack(int start) {
    if (start+1 < _sNodes) {
        for (int i=start+1 ; i<_sNodes; i++) {
            //bool isInterference = interfereEdges(_x[start], _y[start], _x[i], _y[i]);
            //qDebug() << start<<" x "<< i;
            //edgeBacktrack(start, i+1);
            edgeBacktrack(start, i+1,
                          _x[start], _y[start], _x[i], _y[i],
                          start, i);

        }
        edgeBacktrack(start+1);
    }
}

void Graph::edgeBacktrack(int start, int its) {
    if (start+1 < _sNodes) {
        for (int i=its ; i<_sNodes; i++) {
            //qDebug() <<"   "<<  start<<" x "<< i;
        }
        edgeBacktrack(start+1, start+2);
    }
}

void Graph::edgeBacktrack(int start, int its,
                          double x1, double y1, double x2, double y2,
                          int node1, int node2) {

    if (start+1 < _sNodes) {
        for (int i=its ; i<_sNodes; i++) {

            bool sameNodes = checkSameNodes(node1, node2, start, i);
            bool interfer = interceptEdges(x1, y1, x2, y2,
                                           _x[start], _y[start], _x[i], _y[i],sameNodes);
            _fitnes += interfer ? 1 : 0;
            if(interfer) {
                //qDebug()<< "        "<< node1<<"-"<<node2<<" "<<start<<"-"<<i<<"      "  << interfer << "    "<< sameNodes;

                if (sameNodes) {
                    qDebug() << "Specia same node case : ";
                    qDebug() << int(100*x1)<<" "<<int(100*y1)<<" "<<int(100*x2)<<" "<<int(100*y2)\
                             <<"     "<<int(100*_x[start])<<" "<<int(100*_y[start])<<" "<<int(100*_x[i])<<" "<<int(100*_y[i]);
                }
            }
        }
        edgeBacktrack(start+1, start+2, x1, y1, x2, y2,
                      node1, node2);
    }
}

bool Graph::interceptEdges(double x1, double y1, double x2, double y2,
                           double x3, double y3, double x4, double y4, bool hasSameNodes) const {
    if (x1 > x2) {
        if (x3 > x4) {
            return interceptOrderedEdges(x2,y2,x1,y1, x4,y4,x3,y3, hasSameNodes);
        } else {
            return interceptOrderedEdges(x2,y2,x1,y1, x3,y3,x4,y4, hasSameNodes);
        }
    } else {
        if (x3 > x4) {
            return interceptOrderedEdges(x1,y1,x2,y2, x4,y4,x3,y3, hasSameNodes);
        } else {
            return interceptOrderedEdges(x1,y1,x2,y2, x3,y3,x4,y4, hasSameNodes);
        }
    }
}

bool Graph::interceptOrderedEdges(double x1, double y1, double x2, double y2,
                                  double x3, double y3, double x4, double y4, bool hasSameNodes) const {
    bool res1 = interceptOrderedEdges1(x1,y1,x2,y2, x3,y3,x4,y4, hasSameNodes);
    bool res2 = interceptOrderedEdges2(x1,y1,x2,y2, x3,y3,x4,y4, hasSameNodes);
    if (res1 != res2) {
        qDebug() << "Huston we have problem! differen results: "<< res1 <<" "<<res2;
        qDebug() << x1<<" "<<y1<<" "<<x2<<" "<<y2<<"     "<<x3<<" "<<y3<<" "<<x4<<" "<<y4;
    }
    return res2;
}

bool Graph::interceptOrderedEdges1(double x1, double y1, double x2, double y2,
                                   double x3, double y3, double x4, double y4, bool hasSameNodes) const {
    // must be true that x1<=x2 && x3<=x4
    // they have not a same one point
    double dxA = x2-x1;
    double dxB = x4-x3;
    if (0.0==dxA && 0.0==dxB) {
        if (x1==x3) {
            if ((y1<=y3 && y3<=y2) || (y1<=y4 && y4<=y2)) {
                qDebug() << "  <Intercept1 (|| without slope intercept form)";
                return true;
            }
        }
    } else if (!hasSameNodes && 0.0==dxA) {
        double a2 = (y4-y3)/(dxB);
        double qB = y3-a2*x3;
        double y = a2*x1+qB;
        if ((y1<=y && y<=y2) || (y1<=y && y<=y2)) {
            qDebug() << "  <Intercept1 (A without slope intercept form)";
            return true;
        }
    } else if (!hasSameNodes && 0.0==dxB) {
        double a1 = (y2-y1)/(dxA);
        double qA = y1-a1*x1;
        double y = a1*x3+qA;
        if ((y3<=y && y<=y4) || (y3<=y && y<=y4)) {
            //qDebug() << "  <Intercept1 (B without slope intercept form)";
            return true;
        }
    } else {

        // slopes (smernice)
        double a1 = (y2-y1)/(dxA);
        double a2 = (y4-y3)/(dxB);
        double da = a1-a2;

        if (0.0 != da) {
            // interception point[x,y]
            if (!hasSameNodes) {
                double x = (a1*x1 -y1 -a2*x3 +y3)/(da);

                if (x1<=x && x<=x2 && x3<=x && x<=x4) {
                    //qDebug() << "  <Intercept1!";
                    return true;
                }
            }
        } else {
            // if
            double qA = y1-a1*x1;
            if (((x1<=x3 && x3<=x2) || (x1<=x4 && x4<=x2))
                    && y3==a1*x3+qA) {
                qDebug() << "  <Intercept1 (same slopes)";
                return true;
            }
        }
    }

    return false;
}


bool Graph::interceptOrderedEdges2(double x1, double y1, double x2, double y2,
                                   double x3, double y3, double x4, double y4, bool hasSameNodes) const {
    double a1,b1,c1,a2,b2,c2,d,f1,f2,f3,f4;
    a2 = y4-y3;
    b2 = x3-x4;
    c2 = -a2*x3 -b2*y3;

    f1 = a2*x1 +b2*y1 +c2;
    f2 = a2*x2 +b2*y2 +c2;

    if ((f1>0 && f2>0) || (f1<0 && f2<0)) {
        return false;			// A,B v rovnakej polrovine priamky CD
    } else {
        a1 = y2-y1;
        b1 = x1-x2;
        c1 = -a1*x1 -b1*y1;

        f3 = a1*x3 +b1*y3 +c1;
        f4 = a1*x4 +b1*y4 +c1;

        if((f3>0 && f4>0) || (f3<0 && f4<0)) {
            return false;  // A,B v rovnakej polrovine priamky CD
        }

        d = a1*b2 - a2*b1;				//determinant matice
        if (0.0==d){
            // su rovnobezne
            if (a1*c2==a2*c1 && c1*b2==c2*b1) {  // totozne priamky
                if (((y1<=y3 && y3<=y2) || (y1<=y4 && y4<=y2))
                        && ((x1<=x3 && x3<=x2) || (x1<=x4 && x4<=x2))) {
                    qDebug() << "  <Intercept2 (|| without slope intercept form)";
                    return true;
                }
            }
            return false;
        }
        // interception point[x,y]
        //double x = (b1*c2-b2*c1)/d;
        //double y = (a2*c1-a1*c2)/d;
        if (!hasSameNodes){
            return true;
        } else {
            return false;
        }
    }
}


bool Graph::checkSameNodes(int i1, int i2, int i3, int i4) const {
    if (i1==i3 || i1==i4 || i2==i3 || i2==i4) {
        return true;
    }
    return false;
}

//----------- mutate ---------------
void Graph::probabilityMutate(double probability) {
    for (int i=0; i<_sNodes; i++) {
        if ( Util::get()->udD() <= probability) {
            double x,y;
            do {
                x = _x[i] + Util::get()->nD();
                y = _y[i] + Util::get()->nD();
            } while (checkSameNodesValues(x, y, i));

            _x[i] = x;
            _y[i] = y;
        }
    }
    _fitnes = -1;
}

void Graph::mutate() {
    int rindex = Util::get()->uiD();
    double x,y;
    do {
        x = _x[rindex] + Util::get()->nD();
        y = _y[rindex] + Util::get()->nD();
    } while (checkSameNodesValues(x, y, rindex));

    _x[rindex] = x;
    _y[rindex] = y;
    _fitnes = -1;
}

bool Graph::checkSameNodesValues(double x, double y, int index) const {
    for (int i=0 ; i<_sNodes; i++) {
        if (i!=index && x==_x[i] && y==_y[i]) {
            return true;
        }
    }
    return false;
}

//-- crossover --
void Graph::crossover(const Graph &in2, Graph &out1, Graph &out2) const {
    int rindex;
    do {
        rindex = Util::get()->uiD();
    } while (0 == rindex);
    //qDebug() << rindex;
    out1.setNodes(_x, _y,           0, rindex);
    out2.setNodes(in2.x(), in2.y(), 0, rindex);
    out1.setNodes(in2.x(), in2.y(), rindex, _sNodes);
    out2.setNodes(_x, _y,           rindex, _sNodes);
}

