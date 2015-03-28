#include "mainwindow.h"

#include <QTextEdit>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

#include <QFileInfo>
#include <QFile>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QVector>


#include "statistictest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle( tr("EA_K_Graph") );

    //QGridLayout *paramLA = createParamLayout();

    QVBoxLayout *buttonLA = new QVBoxLayout();
    QHBoxLayout *mainLA = new QHBoxLayout();

    runBasicTestPB = new QPushButton(tr("run test"));
    //buttonLA->addLayout(paramLA);
    //buttonLA->addWidget(createFirstExclusiveGroup());
    buttonLA->addWidget(runBasicTestPB);
    buttonLA->addWidget(&promtL1);
    buttonLA->addWidget(&promtL2);
    buttonLA->addWidget(&promtL3);






    mainLA->addLayout(buttonLA);


    QWidget *widget = new QWidget;
    widget->setLayout(mainLA);
    setCentralWidget(widget);




    tested = false;

}

//void MainWindow::runBasicTest() {
//    qDebug() << "SLOT run basic test";
//    StatisticTest statisticTest;
//    input = getParams();
//    output = statisticTest.simpleTest(input);
//    tested = true;
//    resetPlot();

//    promtL1.setText("Success rate: "+QString::number(((double)output.solutions*100)/input.testmax)+"%");
//    promtL2.setText("Mean fitness: "+QString::number(output.meanFitness, 'f', 10));
//    promtL3.setText("Mean fitness call: "+QString::number(output.meanFitnessCall, 'f', 0));
//}




//QGroupBox *MainWindow::createFirstExclusiveGroup() {
//    QGroupBox *groupBox = new QGroupBox();
//    plot1RB = new QRadioButton(tr("Plot1"));
//    plot2RB = new QRadioButton(tr("Plot2"));
//    plot3RB = new QRadioButton(tr("Plot3"));
//    plot3RB->setChecked(true);
//    QVBoxLayout *vbox = new QVBoxLayout;
//    vbox->addWidget(plot1RB);
//    vbox->addWidget(plot2RB);
//    vbox->addWidget(plot3RB);
//    groupBox->setLayout(vbox);
//    return groupBox;
//}



//QGridLayout *MainWindow::createParamLayout() {
//    useGrayCB    = new QCheckBox();
//    useGrayCB->setChecked(C_USEGRAY);
//    tmaxLE       = new QLineEdit(QString::number( C_TMAX ));
//    cmaxLE       = new QLineEdit(QString::number( C_CMAX ));
//    mutbitsLE    = new QLineEdit(QString::number( C_MUTBITS ));
//    kLE          = new QLineEdit(QString::number( C_K ));
//    startLE      = new QLineEdit(QString::number( C_START ));
//    aLE          = new QLineEdit(QString::number( C_A ));
//    bLE          = new QLineEdit(QString::number( C_B ));
//    testMaxLE    = new QLineEdit(QString::number( C_TESTMAX ));
//    sortCB          = new QCheckBox();
//    allNeighborsCB  = new QCheckBox();
//    QLabel *useGrayL = new QLabel(tr("Gray code"));
//    QLabel *tmaxL = new QLabel(tr("t max"));
//    QLabel *cmaxL = new QLabel(tr("c max"));
//    QLabel *mutbitsL = new QLabel(tr("mutbits"));
//    QLabel *kL = new QLabel(tr("k"));
//    QLabel *startL = new QLabel(tr("start"));
//    QLabel *aL = new QLabel(tr("a"));
//    QLabel *bL = new QLabel(tr("b"));
//    QLabel *testMaxL = new QLabel(tr("test max"));
//    QLabel *sortL = new QLabel(tr("sort"));
//    QLabel *allNeighborsL = new QLabel(tr("all neighbors"));

//    QGridLayout *paramLayout = new QGridLayout();

//    paramLayout->addWidget( useGrayL,  0,0 );
//    paramLayout->addWidget( tmaxL,     1,0 );
//    paramLayout->addWidget( cmaxL,     2,0 );
//    paramLayout->addWidget( mutbitsL,  3,0 );
//    paramLayout->addWidget( kL,        4,0 );
//    paramLayout->addWidget( startL,    5,0 );
//    paramLayout->addWidget( aL,        6,0 );
//    paramLayout->addWidget( bL,        7,0 );
//    paramLayout->addWidget( testMaxL,  8,0 );
//    paramLayout->addWidget( sortL,  9,0 );
//    paramLayout->addWidget( allNeighborsL,  10,0 );
//    paramLayout->addWidget( useGrayCB,   0,1 );
//    paramLayout->addWidget( tmaxLE,      1,1 );
//    paramLayout->addWidget( cmaxLE,      2,1 );
//    paramLayout->addWidget( mutbitsLE,   3,1 );
//    paramLayout->addWidget( kLE,         4,1 );
//    paramLayout->addWidget( startLE,     5,1 );
//    paramLayout->addWidget( aLE,         6,1 );
//    paramLayout->addWidget( bLE,         7,1 );
//    paramLayout->addWidget( testMaxLE,   8,1 );
//    paramLayout->addWidget( sortCB,      9,1 );
//    paramLayout->addWidget( allNeighborsCB,  10,1 );


//    QIntValidator *validatorInt     = new QIntValidator(1, 1000000, this);
//    QDoubleValidator *validatorDouble = new QDoubleValidator(-1000000.0, 1000000.1, 2);

//    tmaxLE->setValidator(validatorInt);
//    cmaxLE->setValidator(validatorInt);
//    mutbitsLE->setValidator(validatorInt);
//    kLE->setValidator(validatorInt);
//    startLE->setValidator(validatorDouble);
//    aLE->setValidator(validatorDouble);
//    bLE->setValidator(validatorDouble);
//    testMaxLE->setValidator(validatorInt);


//    return paramLayout;
//}

//HCInput MainWindow::getParams() {
//    if ( tmaxLE->hasAcceptableInput() &&
//         cmaxLE->hasAcceptableInput() &&
//         mutbitsLE->hasAcceptableInput() &&
//         kLE->hasAcceptableInput() &&
//         startLE->hasAcceptableInput() &&
//         aLE->hasAcceptableInput() &&
//         bLE->hasAcceptableInput() &&
//         testMaxLE->hasAcceptableInput()) {

//        return HCInput(tmaxLE->text().toInt(),
//                       cmaxLE->text().toInt(),
//                       useGrayCB->isChecked(),
//                       mutbitsLE->text().toInt(),
//                       kLE->text().toInt(),
//                       startLE->text().toDouble(),
//                       aLE->text().toDouble(),
//                       bLE->text().toDouble(),
//                       testMaxLE->text().toInt(),
//                       allNeighborsCB->isChecked());

//    }
//    qDebug() << "WARNING: not valid input parameter, who knows which one :)";
//    return HCInput();
//}
