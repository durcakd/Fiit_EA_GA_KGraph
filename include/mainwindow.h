#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QGridLayout>
#include <QLayout>
//#include "hcinput.h"
//#include "hcoutput.h"
#include <QRadioButton>
#include <QGroupBox>

//const bool C_USEGRAY = false;
//const int C_TMAX = 100;
//const int C_CMAX = 8;
//const int C_MUTBITS = 1;
//const int C_K = 8;
//const double C_START = 0.5;
//const double C_A = -1.0;
//const double C_B = 1.0;
//const int C_TESTMAX = 100;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);




public slots:

//    void runBasicTest();

private:

    QGridLayout *createParamLayout();
//    QGroupBox *createFirstExclusiveGroup();
//    HCInput getParams();




    QPushButton *runBasicTestPB;

//    HCInput input;
//    HCOutput output;
    bool tested;
    QLabel promtL1;
    QLabel promtL2;
    QLabel promtL3;

    QCheckBox *useGrayCB;
    QLineEdit *tmaxLE;
    QLineEdit *cmaxLE;
    QLineEdit *mutbitsLE;
    QLineEdit *kLE;
    QLineEdit *startLE;
    QLineEdit *aLE;
    QLineEdit *bLE;
    QLineEdit *testMaxLE;
    QCheckBox *sortCB;
    QCheckBox *allNeighborsCB;

    QRadioButton *plot1RB;
    QRadioButton *plot2RB;
    QRadioButton *plot3RB;

    /*
    tmaxLE
    cmaxLE
    mutbitsLE
    kLE
    startLE
    aLE
    bLE
    testMaxLE
    */
};

#endif // MAINWINDOW_H
