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

private:
    void elite(int count, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList);
    void crossover(int count, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList);
    void mutation(int count, std::vector<Graph*> &popList, std::vector<Graph*> &newPopList);
    void newBlood(int count, std::vector<Graph*> &newPopList);

};

#endif


