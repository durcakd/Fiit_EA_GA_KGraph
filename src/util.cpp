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
    a = 0.0;
    b = 1.0;
    normalDist = new  std::normal_distribution<double>(mean, sigma);
    uniformDist = new std::uniform_real_distribution<double>(a,b);
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

void Util::resetGenerator() {
   normalDist->reset();
}

double Util::nd() {
    return (*normalDist)(generator);
}

double Util::ud() {
    return (*uniformDist)(generator);
}
