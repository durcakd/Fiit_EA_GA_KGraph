#include "ga.h"

//#include <math.h>
#include <vector>
#include <algorithm>
#include <QStringBuilder>

#include <QDebug>
#include "util.h"

GA::GA()
{
    printStatistic = false;
}


struct comparator {
    bool operator() (Graph *g1, Graph *g2) {
        return (g1->getFitness() > g2->getFitness());
    }
} GraphComparator;


GAOutput GA::optimize(const GAInput &in)
{
    GAOutput out;
    out.oIsSolution = false;
    out.oResultFitness = 100000000;
    out.oGenCall = 0;
    out.oFitnessCall = 0;
    out.resGraph = NULL;

    Graph::init(in.cNodes);
    Util::get()->setPopSize(in.cPop);

    if (in.sElit+in.sCross+in.sMut+in.sNew != in.cPop ) {
        qDebug() << "WARNING wrong population sizes"; return out; }
    if (in.sCross%2 != 0 ) {
        qDebug() << "WARNING wrong crossover size"; return out; }

    int     fitnessCounter = 0;
    int     bestFitness = out.oResultFitness;
    Graph  *bestGraph = NULL;
    std::vector<Graph*>  popList;
    std::vector<Graph*> newPopList;

    for (int i=0; i< in.cPop; i++) {
        Graph *g = new Graph();
        g->generateNodes();
        popList.push_back( g);
    }

    recalcFitness( popList, fitnessCounter, bestFitness, &bestGraph);
    if (printStatistic) {
        qDebug() << " ;Generacia;Najlepsia fitness;Premerna fitness; Smerodajna odchylka; ";
        qDebug() << getStatistic( 0, fitnessCounter, bestGraph, popList);
    }

    int genit=1;
    while ( genit<in.cGen && !bestGraph->isSolution()) {
        std::sort (popList.begin(), popList.end(), GraphComparator);

        // ELITE
        elite(in.sElit, popList, newPopList);
        // CROSSOVER
        crossover(in.sCross, in.sTourCross, popList, newPopList);
        // MUTATION
        mutation(in.sMut, in.sTourMut, in.cMutProb, popList, newPopList);
        // NEW BLOOD
        newBlood( in.sNew, newPopList);


        // clear old population and copy there new one
        completeClearPop(popList);
        for (unsigned int i=0; i<newPopList.size(); i++) {
            popList.push_back( newPopList.at(i));
        }
        newPopList.clear();

        // calculate fitness off all population and update best
        recalcFitness( popList, fitnessCounter, bestFitness, &bestGraph);

        if (printStatistic) {
            qDebug() << getStatistic( genit, fitnessCounter, bestGraph, popList);
        }

        genit++;
    }
    out.oIsSolution = bestGraph->isSolution();
    out.oResultFitness = bestGraph->getFitness();
    out.oGenCall = genit;
    out.oFitnessCall = fitnessCounter;
    out.resGraph = bestGraph->clone();
    return out;
}

void GA::elite(int count, std::vector<Graph*> &sortedPopList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {
        const Graph *g = sortedPopList.at(i);
        Graph *cloned = g->clone();
        newPopList.push_back(cloned);
    }
}

void GA::crossover(int count, int tournamentSize, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i+=2) {
        const Graph *g1 = getTournamentGraph(tournamentSize, popList);
        const Graph *g2 = getTournamentGraph(tournamentSize, popList);

        Graph *ng1 = new Graph();
        Graph *ng2 = new Graph();

        g1->crossover( *g2, *ng1, *ng2);
        newPopList.push_back( ng1);
        newPopList.push_back( ng2);

    }
}

void GA::mutation(int count, int tournamentSize, double mutProbability, std::vector<Graph*> &sortedPopList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {
        const Graph *g = getTournamentGraph(tournamentSize, sortedPopList);
        Graph *cloned = g->clone();
        if (mutProbability < 0.000001) {
            cloned->mutate();
        } else {
            cloned->probabilityMutate( mutProbability);
        }
        newPopList.push_back( cloned);
    }
}

const Graph *GA::getTournamentGraph(int tournamentSize, std::vector<Graph*> &popList) const {

    int randi = Util::get()->randomGraphIndex();
    const Graph *winner = popList.at(randi);
    for (int i=1; i<tournamentSize; i++) {
        randi = Util::get()->randomGraphIndex();
        Graph *challenger = popList.at(randi);
        if (winner->getFitness() > challenger->getFitness()) {
            winner = challenger;
        }
    }
    return winner;
}

void GA::newBlood(int count, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {
        Graph *g = new Graph();
        g->generateNodes();
        newPopList.push_back( g);
    }
}

void GA::recalcFitness(std::vector<Graph*> &popList, int &fitnessCounter, int &bestFitness, Graph **bestGraph ) {
    for (unsigned int i=0; i<popList.size(); i++) {
        Graph *g = popList.at(i);
        fitnessCounter += g->calcFitness();

        if (g->getFitness() < bestFitness) {
            bestFitness = g->getFitness();
            *bestGraph = g->clone();
        }
    }

}

void GA::completeClearPop(std::vector<Graph*> &popList) {
    if( !popList.empty()) {
        //qDebug() << "pop size before clear"<< popList.size();
        //printPop(popList);
        for (unsigned int i=0; i<popList.size(); i++) {
            const Graph *g = popList.at(i);
            delete g;
        }
        popList.clear();
    }
}

void GA::printPop(std::vector<Graph*> &popList) const {
    for (unsigned int i=0; i<popList.size(); i++) {
        const Graph *g = popList.at(i);
        qDebug() << g->toString();
    }
}

QString GA::getStatistic(int genit, int fitnessCalls, Graph *bestGrap, std::vector<Graph*> &popList) {
    int popSize = popList.size();
    // mean fitness
    double meanFitness = 0.0;
    for (int i=0; i<popSize; i++) {
        const Graph *g = popList.at(i);
        meanFitness += g->getFitness();
    }
    meanFitness /= popSize;

    // SO
    double soFitness = 0.0;
    for (int i=0; i<popSize; i++) {
        const Graph *g = popList.at(i);
        double diff = meanFitness - g->getFitness();
        soFitness += (diff*diff);
    }
    soFitness /= popSize;
    soFitness = sqrt(soFitness);
/*
    QString s = ";  "% QString::number(genit+1)\
            %" ;BF=;"% QString::number( bestGrap->getFitness())\
            %" ;MF=;"% QString::number( meanFitness,'f',2 )\
            %" ;SOF=;"% QString::number( soFitness,'f',2 )\
            %";";
*/
    QString s = ";  "% QString::number(genit+1)\
            %" ;"% QString::number( bestGrap->getFitness())\
            %" ;"% QString::number( meanFitness,'f',2 )\
            %" ;"% QString::number( soFitness,'f',2 )\
            /*%" ;FC=;"% QString::number( fitnessCalls )*/\
            %";";


    return s;
}
