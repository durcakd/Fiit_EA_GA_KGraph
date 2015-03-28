#ifndef UTIL_H
#define UTIL_H

#include <random>
#include <time.h>

class Util {
public:
    static Util* get();

    double nd();

    void setSigma(double sigma);
    void setMean(double mean);
    void resetGenerator();

private:
    inline Util();
    static Util *instance;

    double sigma;
    double mean;
    std::default_random_engine generator;
    std::normal_distribution<double> *distribution;
};
#endif

