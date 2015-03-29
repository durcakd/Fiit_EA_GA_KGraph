#ifndef GAINPUT_H
#define GAINPUT_H

#include <QDebug>

const int C_NODES = 5;
const int C_MAX_TEST = 100;
const int C_MAX_GEN = 2;
const int C_MAX_POP = 20;
const int C_S_ELIT = 3;
const int C_S_CROSS = 8;
const int C_S_MUT = 6;
const int C_S_NEW = 3;
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
            int sNew = C_S_NEW );

    int cNodes;
    int cTest;
    int cGen;
    int cPop;
    int sElit;
    int sCross;
    int sMut;
    int sNew;
};
#endif
