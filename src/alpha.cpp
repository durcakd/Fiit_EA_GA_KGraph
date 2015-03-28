#include "alpha.h"
#include "util.h"

//// define static fields and methods
//bool   Alpha::_isgray;
//double Alpha::_a;
//double Alpha::_b;
//unsigned int Alpha::_k;
//unsigned int Alpha::_mutbits;
//unsigned int Alpha::_pow2tokm1;
//double Alpha::_mindiff;
//double Alpha::_mindiffFitness;
//bool* Alpha::_randBitIndex = NULL;



//void Alpha::init(bool isgray, double a, double b, unsigned int k, unsigned int mutbits)
//{
//    //srand(clock());

//    _isgray = isgray;
//    _a = a;
//    _b = b;
//    _k = k;
//    _mutbits = mutbits;

//    _pow2tokm1 = Util::pow2tokm1(k);
//    _mindiff = Util::minDiff(a, b, _pow2tokm1)/2;
//    _mindiffFitness = _mindiff * _mindiff;


//    if (NULL != _randBitIndex) {
//        delete _randBitIndex;
//    }
//    _randBitIndex = new bool[k];

////    qDebug() << "=======================";
////    qDebug() << "  isgray = " << _isgray;
////    qDebug() << "       a = " << _a;
////    qDebug() << "       b = " << _b;
////    qDebug() << "       k = " << _k;
////    qDebug() << " pow2km1 = " << _pow2tokm1;
////    qDebug() << "    diff = " <<  QString::number(_mindiff,'f',15);
////    qDebug() << " mindiff = " << QString::number(_mindiffFitness,'f',15);
////    qDebug() << "=======================";

//}


// constructor
Alpha::Alpha(uint value) {
}

Alpha::Alpha(double realValue) {

}



//// initial binary ( binaryToGray(0.5))
//// fitness(grayToBinary(x))

//uint Alpha::value() {
//    return _value;
//}

//void Alpha::setValue(uint value) {
//    _value = value;
//}

//double Alpha::realValue() {
//    uint value = _value;
//    if (_isgray) {
//        value = Util::grayToBinary(_value);
//    }
//    return Util::binToReal( _a, _b, _pow2tokm1, value);
//}

//double Alpha::fitness() {
//    const double x = realValue() + C;
//    return x*x;

////    return (realValue()+C)*(realValue()+C);
//}


//std::vector<Alpha *>* Alpha::getNeighborsAll(int count) {
//    std::vector<Alpha *>* neighbors  = new std::vector<Alpha *>();
//    //double real = realValue();
//    //qDebug() << "  orig " << toString();

//    for (int i=0; i<count; i++ ) {
//        uint mutatedValue = _value;
//        for(int l=0; l<_k; l++ ) {
//            double rn = (rand()%1000)/1000.0;
//            if(rn < 1.0/_k) {
//                mutatedValue = negateBit(mutatedValue, l);
//            }
//        }


//        Alpha* mut = new Alpha(mutatedValue);
//        neighbors->push_back(mut);
//        //qDebug() << "     m " << mut->toString();
//    }
//    return neighbors;
//}

//std::vector<Alpha *>* Alpha::getNeighborsRandom(int count) {
//    std::vector<Alpha *>* neighbors  = new std::vector<Alpha *>();
//    //qDebug() << "  orig " << toString();

//    for (int nb=0; nb<count; nb++ ) {
//        clearRandArray();
//        uint mutatedValue = _value;
//        uint pos;
//        for (int i=0; i<_mutbits; i++ ){
//            // find random not mutated bit
//            do {
//                pos = rand()%_k;
//            } while (_randBitIndex[pos]);

//            _randBitIndex[pos] = true;   // true == mutaded
//            mutatedValue = negateBit(mutatedValue, pos);
//        }

//        Alpha* mut = new Alpha(mutatedValue);
//        neighbors->push_back(mut);
//        //qDebug() << "     m " << mut->toString();
//    }
//    return neighbors;
//}

//void Alpha::clearRandArray() {
//    for(int i=0; i<_k; i++) {
//        _randBitIndex[i] = false;
//    }
//}


//uint Alpha::negateBit(uint i) {
//    return negateBit(_value, i);
//}

//uint Alpha::negateBit(uint value, uint i) {
//    return value ^ (1u << i) ;
//}

//bool Alpha::checkSolution(double fitness) {
//    if( fitness <= _mindiffFitness){
//        return true;
//    }
//    return false;
//}

//bool Alpha::checkSolution() {
//    double real = realValue();
//    if( -C-_mindiff < real  &&  real < -C+_mindiff) {
//        //qDebug() << -C-_mindiff << " < " << real << " < " << -C+_mindiff;
//        return true;
//    }
//    return false;
//}

//QString Alpha::toString() {
//    QString s =  QString::number(value()) \
//            + "\t " + Util::bits(value(), _k) \
//            + "\t real= " + Util::str(realValue()) \
//            + "\t fitness=" + Util::str(fitness());
//    return s;


//}
