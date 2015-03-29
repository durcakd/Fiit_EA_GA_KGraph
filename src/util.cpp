#include "util.h"

Util *Util::instance;

Util *Util::get() {
    if (NULL == instance) {
        instance = new Util();
    }
    return instance;
}

Util::Util(){
    sigma = 0.1;
    mean = 0.0;
    dA = 0.0;
    dB = 1.0;
    iA = 0;
    iB = 2;
    popSize = 0;

    normalDist = new  std::normal_distribution<double>(mean, sigma);
    uniRealDist = new std::uniform_real_distribution<double>(dA,dB);
    uniIntDist = new std::uniform_int_distribution<int>(iA,iB);
    popDist = new std::uniform_int_distribution<int>(0,popSize);
    generator.seed(time(0));
}

void Util::setSigma(double sigma) {
    this->sigma = sigma;
    delete  normalDist;
    normalDist= new  std::normal_distribution<double>(mean, sigma);
}

void Util::setMean(double mean) {
    this->mean = mean;
    delete  normalDist;
    normalDist= new  std::normal_distribution<double>(mean, sigma);
}

void Util::setIntDistUpBound(int ib) {
    if (ib<3) {
        ib = 3;
    }
    this->iB = ib-1;
    delete  uniIntDist;
    uniIntDist = new std::uniform_int_distribution<int>(iA,iB);
}

void Util::setPopSize(int popSize) {
    if (popSize<1) {
        popSize = 1;
    }
    this->popSize = popSize-1;
    delete  popDist;
    popDist = new std::uniform_int_distribution<int>(0,popSize);
}

void Util::resetGenerator() {
   normalDist->reset();
   uniRealDist->reset();
   uniIntDist->reset();
   popDist->reset();
}

double Util::nd() {
    return (*normalDist)(generator);
}

double Util::udD() {
    return (*uniRealDist)(generator);
}

int Util::uiD() {
    return (*uniIntDist)(generator);
}

int Util::randomGraphIndex() {
    return (*popDist)(generator);
}
