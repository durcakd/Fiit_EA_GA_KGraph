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
    distribution = new  std::normal_distribution<double>(mean, sigma);
    generator.seed(time(0));
}

void Util::setSigma(double sigma) {
    this->sigma = sigma;
    delete  distribution;
    distribution= new  std::normal_distribution<double>(mean, sigma);
}

void Util::setMean(double mean) {
    this->mean = mean;
    delete  distribution;
    distribution= new  std::normal_distribution<double>(mean, sigma);
}

void Util::resetGenerator() {
   distribution->reset();
}

double Util::nd() {
    return (*distribution)(generator);
}
