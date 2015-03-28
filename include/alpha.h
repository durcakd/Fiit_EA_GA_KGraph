#ifndef ALPHA_H
#define ALPHA_H


#include "util.h"
#include "math.h"

#include <vector>
#include <QDebug>
#include <bitset>

const double C = 0.01;

class Alpha
{

public:
    Alpha(uint value);
    Alpha(double realValue);

    static void init(bool isgray, double a, double b, unsigned int k, unsigned int mutbits);

    double fitness();

    uint value();
    void setValue(uint value);
    double realValue();
    QString printBin();

    uint negateBit(uint i);
    uint negateBit(uint value, uint i);
    void clearRandArray();

    bool checkSolution(double fitness);
    bool checkSolution();
    QString toString();


    std::vector<Alpha*>* getNeighborsAll(int count);
    std::vector<Alpha*>* getNeighborsRandom(int count);

private:

    //  mutation();


    static bool   _isgray;
    static double _a;
    static double _b;
    static unsigned int _k;
    static unsigned int _mutbits;
    static unsigned int _pow2tokm1;
    static double _mindiff;
    static double _mindiffFitness;
    static bool* _randBitIndex;

    uint _value;

};

#endif


