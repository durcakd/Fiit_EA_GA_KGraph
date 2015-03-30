#ifndef STATISTICTEST_H
#define STATISTICTEST_H


#include "gainput.h"
#include "gaoutput.h"

class StatisticTest
{

public:
    StatisticTest();

    GAOutput simpleTest(GAInput in);

private:
    void calcStatistic(std::vector<GAOutput> &results, GAOutput &outTest) const;
    QString StatisticToString( GAOutput &outTest) const;
};

#endif


