#include "gainput.h"

GAInput::GAInput(int cNodes,
                 int cTest,
                 int cGen,
                 int cPop,
                 int sElit,
                 int sCross,
                 int sMut,
                 int sNew ) {

    this->cNodes = cNodes;
    this->cTest = cTest;
    this->cGen = cGen;
    this->cPop = cPop;
    this->sElit = sElit;
    this->sCross = sCross;
    this->sMut = sMut;
    this->sNew = sNew;
}
