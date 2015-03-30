#ifndef GA_H
#define GA_H


#include "gainput.h"
#include "gaoutput.h"
#include "graph.h"

class GA
{

public:
    GA();

    GAOutput optimize(const GAInput &in);
    inline void enableStatistics(bool enable) { printStatistic = enable;}

private:
    void elite(int count, std::vector<Graph*> &sortedPopList, std::vector<Graph*> &newPopList);
    void crossover(int count, int tournamentSize, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList);
    void mutation(int count, int tournamentSize, double mutProbability, std::vector<Graph*> &sortedPopList, std::vector<Graph*> &newPopList);
    void newBlood(int count, std::vector<Graph*> &newPopList);

   // const Graph *getRandomGraph(std::vector<Graph*> &popList) const;
    void recalcFitness(std::vector<Graph*> &popList, int &fitnessCounter, int &bestFitness, Graph **bestGraph );
    const Graph *getTournamentGraph(int tournamentSize, std::vector<Graph*> &popList) const;
    void completeClearPop(std::vector<Graph*> &popList);
    void printPop(std::vector<Graph*> &popList) const;

    QString getStatistic(int genit, int fitnessCalls, Graph *bestGrap, std::vector<Graph*> &popList);

    bool printStatistic;
};

#endif


