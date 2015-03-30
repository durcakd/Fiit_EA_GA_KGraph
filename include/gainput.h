#ifndef GAINPUT_H
#define GAINPUT_H

#include <QDebug>

const int C_NODES = 9;
const int C_MAX_TEST = 1;
const int C_MAX_GEN = 50;
const int C_MAX_POP = 30;
const int C_S_ELIT = 3;
const int C_S_CROSS = 12;
const int C_S_MUT = 12;
const int C_S_NEW = 3;

const int C_S_TOURNEY_CROSS = 2;
const int C_S_TOURNEY_MUT = 2;
const double C_SIGMA = 0.1;

class GAInput
{
public:
    GAInput(int cNodes = C_NODES,
            int cTest = C_MAX_TEST,
            int cGen = C_MAX_GEN,
            int cPop = C_MAX_POP,
            int sElit = C_S_ELIT,
            int sCross = C_S_CROSS,
            int sMut = C_S_MUT,
            int sNew = C_S_NEW,
            int sTourCross = C_S_TOURNEY_CROSS,
            int sTourMut = C_S_TOURNEY_MUT,
            double cMutProb = -1.0 );

    int cNodes;
    int cTest;
    int cGen;
    int cPop;
    int sElit;
    int sCross;
    int sMut;
    int sNew;
    int sTourCross;
    int sTourMut;
    double cMutProb;
};
#endif
