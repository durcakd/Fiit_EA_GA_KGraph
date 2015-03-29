#include "ga.h"

#include <math.h>
#include <vector>

#include <QDebug>
#include "util.h"

GA::GA()
{
}



GAOutput GA::optimize(const GAInput &in)
{
    qDebug() <<"====================================";
    Graph::init(in.cNodes);

    int fitnessCounter = 0;
    int  bestFitness = 10000000;
    Graph*  bestGraph = NULL;

    GAOutput out;
    out.isSolution = false;
    //out.resultFitness = 100000000;
    //out.fitnessCount = 0;

    std::vector<Graph*> popList(in.cPop);
    for (int i=0; i< in.cPop; i++) {
        Graph *g = new Graph();
        g->generateNodes();
        popList.push_back( g);

        fitnessCounter += g->calcFitness();
        if (g->getFitness() < bestFitness) {
            bestFitness = g->getFitness();
            bestGraph = g->clone();
        }
    }


    for (int genit=0; genit<in.cGen; genit++) {

        std::vector<Graph*> newPopList(in.cPop);

        // ELITE
        elite(in.sElit, popList, newPopList);

        // CROSSOVER
        crossover(in.sCross, popList, newPopList);

        // MUTATION
        mutation(in.sMut, popList, newPopList);

        // NEW BLOOD
        newBlood( in.sNew, newPopList);


        qDebug() <<"---------"<< genit <<"  BF="<<bestFitness;
    }

    return out;
}

void GA::elite(int count, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {

    }
}

void GA::crossover(int count, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {

    }
}

void GA::mutation(int count, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {

    }
}

void GA::newBlood(int count, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {
        Graph *g = new Graph();
        g->generateNodes();
        newPopList.push_back( g);
    }
}
