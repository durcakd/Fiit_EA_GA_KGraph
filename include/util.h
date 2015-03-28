#ifndef UTIL_H
#define UTIL_H

#include <random>
#include <time.h>

class Util {
public:
    static Util* get();

    double nd();
    double ud();

    void setSigma(double sigma);
    void setMean(double mean);
    void resetGenerator();

private:
    inline Util();
    static Util *instance;

    std::default_random_engine generator;

    double sigma;
    double mean;
    std::normal_distribution<double> *normalDist;

    double a;
    double b;
    std::uniform_real_distribution<double> *uniformDist;
};
#endif

