#include "ga.h"

//#include <math.h>
#include <vector>
#include <algorithm>

#include <QDebug>
#include "util.h"

GA::GA()
{
}


struct comparator {
    bool operator() (Graph *g1, Graph *g2) {
        return (g1->getFitness() > g2->getFitness());
    }
} GraphComparator;


GAOutput GA::optimize(const GAInput &in)
{
    qDebug() <<"====================================";
    GAOutput out;
    out.isSolution = false;
    Graph::init(in.cNodes);

    if (in.sElit+in.sCross+in.sMut+in.sNew != in.cPop ) {
        qDebug() << "WARNING wrong population sizes"; return out; }
    if (in.sCross%2 != 0 ) {
        qDebug() << "WARNING wrong crossover size"; return out; }


    int     fitnessCounter = 0;
    int     bestFitness = 10000000;
    Graph  *bestGraph = NULL;
    std::vector<Graph*>  popList;
    std::vector<Graph*> newPopList;


    //out.resultFitness = 100000000;
    //out.fitnessCount = 0;



    for (int i=0; i< in.cPop; i++) {
        Graph *g = new Graph();
        g->generateNodes();
        fitnessCounter += g->calcFitness();

        if (g->getFitness() < bestFitness) {
            bestFitness = g->getFitness();
            bestGraph = g->clone();
        }

        popList.push_back( g);
    }

    qDebug() << "best "<<bestGraph->toString();

    for (int genit=0; genit<in.cGen; genit++) {
        qDebug() << genit << ". ==================================";
        std::sort (popList.begin(), popList.end(), GraphComparator);
        printPop(popList);


        // clear new population
        clearPop(newPopList);


        // ELITE
        elite(in.sElit, popList, newPopList);

        // CROSSOVER
        crossover(in.sCross, in.sTourCross, popList, newPopList);

        // MUTATION
        mutation(in.sMut, in.sTourMut, popList, newPopList);

        // NEW BLOOD
        newBlood( in.sNew, newPopList);


        qDebug() <<"---------"<< genit <<"  BF="<<bestFitness;
    }

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

void GA::mutation(int count, int tournamentSize, std::vector<Graph*> &sortedPopList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {
        const Graph *g = getTournamentGraph(tournamentSize, sortedPopList);
        Graph *cloned = g->clone();
        cloned->mutate(); // TODO which mutation?
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

//const Graph *GA::getRandomGraph(std::vector<Graph*> &popList) const {
//    int i = Util::get()->randomGraphIndex();
//    return popList.at(i);;
//}

void GA::newBlood(int count, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {
        Graph *g = new Graph();
        g->generateNodes();
        newPopList.push_back( g);
    }
}

void GA::clearPop(std::vector<Graph*> &popList) {
    if( !popList.empty()) {
        qDebug() << "pop size before clear"<< popList.size();
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
