
#include <QDebug>
#include "statistictest.h"

StatisticTest::StatisticTest()
{

}


//HCOutput StatisticTest::simpleTest(HCInput in)
//{
//    qDebug() << "all nei  " << in.allNeighbors;
//    HCOutput outTest;
//    outTest.meanFitness = 0.0;
//    outTest.meanFitnessCall = 0.0;
//    outTest.solutions = 0;

//    srand(time(NULL));
//    in.fill1RunChart = true;
//    for (int i=0; i<in.testmax; i++) {

//        HillClimber hillClimber;
//        HCOutput out = hillClimber.optimaze(in);

//        if (0 == i) {
//            outTest.vAlphaF = out.vAlphaF;
//            outTest.vfinalAlphaF = out.vfinalAlphaF;
//        }

//        in.fill1RunChart = false;
//        //qDebug() << i << "\t" << out.isSolution \
//                 << "\t" << out.fitnessCount \
//                 << "\t" << out.tCount \
//                 << "\t" << out.resultFitness;


//        outTest.testFitness.append(out.resultFitness);
//        outTest.testFitnessCalls.append(out.fitnessCount);
//        outTest.meanFitness += out.resultFitness;
//        outTest.meanFitnessCall += out.fitnessCount;
//        outTest.solutions += out.isSolution ? 1 : 0;

//    }
//    outTest.meanFitnessCall /= in.testmax;
//    outTest.meanFitness /= outTest.solutions;
//    qDebug() << "all nei  " << in.allNeighbors;
//    return outTest;
//}
