#ifndef UTIL_H
#define UTIL_H

#include <random>
#include <time.h>

class Util {
public:
    static Util* get();

    double nd();
    double udD();
    int uiD();

    void setSigma(double sigma);
    void setMean(double mean);
    void setIntDistUpBound(int ib);
    void resetGenerator();

private:
    inline Util();
    static Util *instance;

    std::default_random_engine generator;

    double sigma;
    double mean;
    std::normal_distribution<double> *normalDist;

    double dA;
    double dB;
    std::uniform_real_distribution<double> *uniRealDist;

    int iA;
    int iB;
    std::uniform_int_distribution<int> *uniIntDist;
};
#endif

