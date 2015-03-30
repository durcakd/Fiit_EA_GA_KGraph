#include "statistictest.h"

#include <QDebug>

#include "ga.h"
#include "graph.h"


StatisticTest::StatisticTest()
{

}


GAOutput StatisticTest::simpleTest(GAInput in)
{
    GAOutput outTest;
    Graph *bestGraph = NULL;

    std::vector<GAOutput> results;

    for (int i=0; i<in.cTest; i++) {

        GA ga;
        ga.enableStatistics( 1==in.cTest);
        GAOutput out = ga.optimize(in);
        results.push_back(out);

        if (NULL == bestGraph
                || out.resGraph->getFitness() < bestGraph->getFitness()) {
            delete bestGraph;
            bestGraph = out.resGraph;
        }

    }

    outTest.resGraph = bestGraph;
    calcStatistic(results, outTest);
    qDebug() << in.toString() <<outTest.testOutToString();
    return outTest;
}


void StatisticTest::calcStatistic(std::vector<GAOutput> &results, GAOutput &outTest) const {
    double meanFitness      = 0.0;
    double soFitness        = 0.0;
    double meanGenCalls     = 0.0;
    double soGenCalls       = 0.0;
    double meanFitnessCalls = 0.0;
    double soFitnessCalls   = 0.0;
    int solutionCount       = 0;
    int resSize = results.size();

    // solution counts, MEAN fitness, gen calls, fitness calls
    std::vector<GAOutput>::const_iterator it = results.cbegin();
    for (; it!=results.cend(); it++) {
        meanFitness      += it->oResultFitness;
        meanGenCalls     += it->oGenCall;
        meanFitnessCalls += it->oFitnessCall;
        solutionCount    += it->oIsSolution ? 1 : 0;
    }
    meanFitness      /= resSize;
    meanGenCalls     /= resSize;
    meanFitnessCalls /= resSize;

    // SO fitness, gen calls, fitness calls
    it = results.cbegin();
    for (; it!=results.cend(); it++) {
        double dFitness      = meanFitness - it->oResultFitness;
        double dGenCalls     = meanGenCalls - it->oGenCall;
        double dFitnessCalls = meanFitnessCalls - it->oFitnessCall;
        soFitness      += dFitness*dFitness;
        soGenCalls     += dGenCalls*dGenCalls;
        soFitnessCalls += dFitnessCalls*dFitnessCalls;
    }
    soFitness = sqrt(soFitness/resSize);
    soGenCalls = sqrt(soGenCalls/resSize);
    soFitnessCalls = sqrt(soFitnessCalls/resSize);

    outTest.tSolutions       = solutionCount;
    outTest.tSuccess         = ((double)solutionCount)*100.0/resSize;
    outTest.tMeanFitness     = meanFitness;
    outTest.tMeanGenCall     = meanGenCalls;
    outTest.tMeanFitnessCall = meanFitnessCalls;
    outTest.tSoFitness       = soFitness;
    outTest.tSoGenCall       = soGenCalls;
    outTest.tSoFitnessCall   = soFitnessCalls;
}


