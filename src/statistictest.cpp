
#include <QDebug>
#include "statistictest.h"
#include "ga.h"
#include "graph.h"

StatisticTest::StatisticTest()
{

}


GAOutput StatisticTest::simpleTest(GAInput in)
{
    qDebug() << "TEST ===========================================";
    GAOutput outTest;
    outTest.tMeanFitness = 0.0;
    outTest.tMeanFitnessCall = 0.0;
    outTest.tSolutions = 0;
    outTest.resGraph = NULL;
    Graph *bestGraph = NULL;

    //in.fill1RunChart = true;
    for (int i=0; i<in.cTest; i++) {

        GA ga;
        GAOutput out = ga.optimize(in);

//        if (0 == i) {
//            outTest.vAlphaF = out.vAlphaF;
//            outTest.vfinalAlphaF = out.vfinalAlphaF;
//        }

        //in.fill1RunChart = false;
        qDebug() << i+1 << ";\t" << (out.oIsSolution?"1":"0") \
                 << ";\t" << out.oResultFitness \
                 << ";\t" << out.oGenCall \
                 << ";\t" << out.oFitnessCall;


//        outTest.testFitness.append(out.oResultFitness);
//        outTest.testFitnessCalls.append(out.oFitnessCall);
        outTest.tMeanFitness += out.oResultFitness;
        outTest.tMeanFitnessCall += out.oFitnessCall;
        outTest.tSolutions += out.oIsSolution ? 1 : 0;

        if (NULL == bestGraph
                || out.resGraph->getFitness() < bestGraph->getFitness()) {
            delete bestGraph;
            bestGraph = out.resGraph;
        }

    }
    qDebug() << "TEST ends";
    outTest.tMeanFitnessCall /= in.cTest;
    outTest.tMeanFitness = 0==outTest.tSolutions ? -1: outTest.tMeanFitness = outTest.tSolutions;
    outTest.resGraph = bestGraph;
    return outTest;
}
