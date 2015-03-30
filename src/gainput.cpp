#include "gainput.h"
#include <QStringBuilder>

GAInput::GAInput(int cNodes,
                 int cTest,
                 int cGen,
                 int cPop,
                 int sElit,
                 int sCross,
                 int sMut,
                 int sNew,
                 int sTourCross,
                 int sTourMut,
                 double cMutProb) {

    this->cNodes = cNodes;
    this->cTest = cTest;
    this->cGen = cGen;
    this->cPop = cPop;
    this->sElit = sElit;
    this->sCross = sCross;
    this->sMut = sMut;
    this->sNew = sNew;
    this->sTourCross = sTourCross;
    this->sTourMut = sTourMut;
    this->cMutProb = cMutProb;
}

QString GAInput::toString() const {
    QString s = ";nodes=;"% QString::number( cNodes )\
            %" ;cPop=;"% QString::number( cPop )\
            %" ;sElit=;"% QString::number( sElit )\
            %" ;sCross=;"% QString::number( sCross )\
            %" ;sMut=;"% QString::number( sMut )\
            %" ;sNew=;"% QString::number( sNew )\
            %" ;sTourCross=;"% QString::number( sTourCross )\
            %" ;sTourMut=;"% QString::number( sTourMut )\
            %";";
    return s;
}
