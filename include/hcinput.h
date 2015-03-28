#ifndef HCINPUT_H
#define HCINPUT_H

#include <QDebug>

class HCInput
{

public:
    HCInput(uint tmax = 100,
            uint cmax = 4,
            bool useGray = false,
            uint mutbits = 1,
            uint k = 8,
            double start = 0.5,
            double a = -1.0,
            double b = 1.0,
            int testmax = 100,
            bool allNeighbors = false,
            bool fill1RunChart = false);


    uint tmax;
    uint cmax;
    bool useGray;
    uint mutbits;
    uint k;
    double start;
    double a;
    double b;
    int testmax;
    bool allNeighbors;

    bool fill1RunChart;
};
#endif
