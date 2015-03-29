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
    Graph::init(in.cNodes);

    int     fitnessCounter = 0;
    int     bestFitness = 10000000;
    Graph  *bestGraph = NULL;
    std::vector<Graph*>  popList;
    std::vector<Graph*> newPopList;

    GAOutput out;
    out.isSolution = false;
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
        qDebug() << "NEW GENERATION";
        std::sort (popList.begin(), popList.end(), GraphComparator);
        printPop(popList);

        qDebug() << "Manage new";
        if( !newPopList.empty()) {
          qDebug() << "new " << newPopList.size();
            //printPop(newPopList);

            for (unsigned int i=0; i<popList.size(); i++) {
                const Graph *g = popList.at(i);
                delete g;
            }

            newPopList.clear();
            qDebug() << "new after clear " << newPopList.size();
            printPop(newPopList);
        }



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

void GA::elite(int count, std::vector<Graph*> &sortedPopList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {


    }
}

void GA::crossover(int count, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList) {
    for (int i=0; i<count; i++) {

    }
}

void GA::mutation(int count, std::vector<Graph*> &sortedPopList, std::vector<Graph*> &newPopList) {
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


void GA::printPop(std::vector<Graph*> &popList) {
    for (unsigned int i=0; i<popList.size(); i++) {
        const Graph *g = popList.at(i);
        qDebug() << g->toString();
    }
}
