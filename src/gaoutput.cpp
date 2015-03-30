#include "gaoutput.h"
#include <QStringBuilder>


GAOutput::GAOutput()
{
}

QString GAOutput::testOutToString() const {
    QString s = ";success=;"% QString::number( tSuccess,'f',2 )\
            %" ;MF=;"% QString::number( tMeanFitness,'f',2 )\
            %" ;SOF=;"% QString::number( tSoFitness,'f',2 )\
            %" ;MG=;"% QString::number( tMeanGenCall,'f',2 )\
            %" ;SOG=;"% QString::number( tSoGenCall,'f',2 )\
            %" ;MFC=;"% QString::number( tMeanFitnessCall,'f',2 )\
            %" ;SOFC=;"% QString::number( tSoFitnessCall,'f',2 )\
            %";";
    return s;
}
