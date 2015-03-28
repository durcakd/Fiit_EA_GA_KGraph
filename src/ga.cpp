#include "ga.h"

#include <math.h>
#include <vector>

#include <QDebug>
#include "util.h"

GA::GA()
{
}

void GA::valuesTable(HCInput &in)
{

    Alpha::init(false, in.a, in.b, in.k, in.mutbits);
    uint ovalue, binValue;

    double pow2tokm1 = Util::pow2tokm1(in.k);
    if(in.useGray){
        ovalue = Util::binaryToGray(pow2tokm1);
    } else {
        ovalue = pow2tokm1;
    }
    for(uint u=0; u<pow2tokm1+1; u++ ) {
        if (in.useGray) {
            binValue = Util::binaryToGray(u);
        } else {
            binValue = u;
        }
        Alpha alp(binValue);

        QString diff = Util::bits( ovalue ^ alp.value(), in.k);

        qDebug() << u << "\t" << alp.value() \
                 << "\t" << Util::str(alp.realValue()) \
                 << "\t" << Util::str(alp.fitness()) \
                 << "\t" << diff << "   " << diff.count('1');
        ovalue = alp.value();
    }

}

HCOutput GA::optimaze(const HCInput &in)
{
    HCOutput out;
    out.isSolution = false;
    out.resultFitness = 1.0;
    out.tCount = in.tmax;
    out.fitnessCount = 0;

    //vfinalAlphaF;
    //vAlphaF;


    int fitnessCount = 0;

    Alpha::init(in.useGray, in.a, in.b, in.k, in.mutbits);
    //qDebug() << "------------";

    Alpha alfa(in.start);
    Alpha finalAlfa( alfa.value());
    double finalFitness = finalAlfa.fitness();

    out.resultFitness = finalFitness;
    if (in.fill1RunChart) {
        out.vfinalAlphaF.append(finalFitness);
        out.vAlphaF.append(finalFitness);
    }
    //qDebug() << "start optimize in alfa: " << alfa.toString();
    bool solution = false;
    for (int i=0; i < in.tmax; i++) {
        solution = out.isSolution;
        //qDebug();
        // qDebug() << "alfa:  " << alfa.toString();

        // generate neighborhood from alfa

        std::vector<Alpha*> *p_neighbors;
        if(in.allNeighbors) {
            p_neighbors = alfa.getNeighborsAll(in.cmax);
        } else {
            p_neighbors = alfa.getNeighborsRandom(in.cmax);
        }
        std::vector<Alpha*> &neighbors = *p_neighbors;
        std::vector<Alpha*>::const_iterator it = neighbors.begin();
        Alpha bestNeighbor( (*it)->value());
        double bestNeighborFitness = bestNeighbor.fitness();
        fitnessCount++;
        while (++it != neighbors.end()) {
            fitnessCount++;
            double itFitness = (*it)->fitness();
            if ( bestNeighborFitness > itFitness) {
                bestNeighbor.setValue((*it)->value());
                bestNeighborFitness = itFitness;
            }
        }
        //qDebug() << "best:  " << bestNeighbor.toString();


        if( bestNeighborFitness < finalFitness ) {
            finalFitness = bestNeighborFitness;
            finalAlfa = bestNeighbor;
            //qDebug() << "final: " << finalAlfa.toString() << endl << "-------";

            out.resultFitness = finalFitness;
            //qDebug() << "solution: "<< bestNeighbor.checkSolution(bestNeighborFitness);
            //qDebug() << "solution: "<< bestNeighbor.checkSolution();
            if(bestNeighbor.checkSolution()) {
                //qDebug() << "solution " << i+1;

                out.isSolution = true;

                out.tCount = i+1;
                out.fitnessCount = fitnessCount;
            }
        }

        alfa.setValue( bestNeighbor.value());

        if (in.fill1RunChart && !solution) {
            out.vfinalAlphaF.append(finalFitness);
            out.vAlphaF.append(bestNeighborFitness);
        }
    }


    if (!out.isSolution) {
        out.tCount = in.tmax;
        out.fitnessCount = fitnessCount;
    }
    return out;
}

