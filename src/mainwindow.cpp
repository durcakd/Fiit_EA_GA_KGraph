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
#include "ga.h"



#include "statistictest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle( tr("EA_K_Graph") );

    QGridLayout *paramLA = createParamLayout();
    QVBoxLayout *buttonLA = new QVBoxLayout();
    QHBoxLayout *mainLA = new QHBoxLayout();

    runTestPB = new QPushButton(tr("Run test"));
    buttonLA->addLayout(paramLA);
    buttonLA->addWidget(createFirstExclusiveGroup());
    buttonLA->addWidget(runTestPB);
    buttonLA->addWidget(&promtL1);
    buttonLA->addWidget(&promtL2);
    buttonLA->addWidget(&promtL3);

    mainLA->addLayout(buttonLA);

    QWidget *widget = new QWidget;
    widget->setLayout(mainLA);
    setCentralWidget(widget);

    tested = false;

    QObject::connect( runTestPB, SIGNAL(clicked()),
                      this, SLOT(runTest()));

    runTest();
}

void MainWindow::runTest() {
    qDebug() << "Run test...";
    //StatisticTest statisticTest;
    input = getParams();
    //output = statisticTest.simpleTest(input);
    tested = true;

    GA ga;
    ga.optimize(input);

//    promtL1.setText("Success rate: "+QString::number(((double)output.solutions*100)/input.testmax)+"%");
//    promtL2.setText("Mean fitness: "+QString::number(output.meanFitness, 'f', 10));
//    promtL3.setText("Mean fitness call: "+QString::number(output.meanFitnessCall, 'f', 0));
}




QGroupBox *MainWindow::createFirstExclusiveGroup() {
    QGroupBox *groupBox = new QGroupBox();
    ga1RB = new QRadioButton(tr("GA 1"));
    ga2RB = new QRadioButton(tr("GA 2"));
    ga3RB = new QRadioButton(tr("GA 3"));
    ga1RB->setChecked(true);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(ga1RB);
    vbox->addWidget(ga2RB);
    vbox->addWidget(ga3RB);
    groupBox->setLayout(vbox);
    return groupBox;
}



QGridLayout *MainWindow::createParamLayout() {
    QLabel *cNodesL = new QLabel(tr("Nodes"));
    QLabel *cTestL = new QLabel(tr("Tests"));
    QLabel *cGenL = new QLabel(tr("Gen count"));
    QLabel *cPopL = new QLabel(tr("Pop size "));
    QLabel *sElitL = new QLabel(tr("Elit ratio"));
    QLabel *sCrossL = new QLabel(tr("Cross ratio"));
    QLabel *sMutL = new QLabel(tr("Mut ratio"));
    QLabel *sNewL = new QLabel(tr("New ratio"));

    cNodesLE    = new QLineEdit(QString::number( C_NODES ));
    cTestLE     = new QLineEdit(QString::number( C_MAX_TEST ));
    cGenLE      = new QLineEdit(QString::number( C_MAX_GEN ));
    cPopLE      = new QLineEdit(QString::number( C_MAX_POP ));
    sElitLE     = new QLineEdit(QString::number( C_S_ELIT ));
    sCrossLE    = new QLineEdit(QString::number( C_S_CROSS ));
    sMutLE      = new QLineEdit(QString::number( C_S_MUT ));
    sNewLE      = new QLineEdit(QString::number( C_S_NEW ));

    QGridLayout *paramLayout = new QGridLayout();

    paramLayout->addWidget( cNodesL,  0,0 );
    paramLayout->addWidget( cTestL,     1,0 );
    paramLayout->addWidget( cGenL,     2,0 );
    paramLayout->addWidget( cPopL,  3,0 );
    paramLayout->addWidget( sElitL,        4,0 );
    paramLayout->addWidget( sCrossL,    5,0 );
    paramLayout->addWidget( sMutL,        6,0 );
    paramLayout->addWidget( sNewL,        7,0 );

    paramLayout->addWidget( cNodesLE,   0,1 );
    paramLayout->addWidget( cTestLE,      1,1 );
    paramLayout->addWidget( cGenLE,      2,1 );
    paramLayout->addWidget( cPopLE,   3,1 );
    paramLayout->addWidget( sElitLE,         4,1 );
    paramLayout->addWidget( sCrossLE,     5,1 );
    paramLayout->addWidget( sMutLE,         6,1 );
    paramLayout->addWidget( sNewLE,         7,1 );

    QIntValidator *ssValidator     = new QIntValidator(1, 50, this);
    QIntValidator *pValidator     = new QIntValidator(1, 100, this);
    QIntValidator *mValidator     = new QIntValidator(1, 100000, this);
    cNodesLE->setValidator( ssValidator);
    cTestLE->setValidator( mValidator);
    cGenLE->setValidator( mValidator);
    cPopLE->setValidator( mValidator);
    sElitLE->setValidator( pValidator);
    sCrossLE->setValidator( pValidator);
    sMutLE->setValidator( pValidator);
    sNewLE->setValidator( pValidator);

    return paramLayout;
}

GAInput MainWindow::getParams() {
    if ( cNodesLE->hasAcceptableInput() &&
         cTestLE->hasAcceptableInput() &&
         cGenLE->hasAcceptableInput() &&
         cPopLE->hasAcceptableInput() &&
         sElitLE->hasAcceptableInput() &&
         sCrossLE->hasAcceptableInput() &&
         sMutLE->hasAcceptableInput() &&
         sNewLE->hasAcceptableInput()) {

        return GAInput(cNodesLE->text().toInt(),
                       cTestLE->text().toInt(),
                       cGenLE->text().toInt(),
                       cPopLE->text().toInt(),
                       sElitLE->text().toInt(),
                       sCrossLE->text().toInt(),
                       sMutLE->text().toInt(),
                       sNewLE->text().toInt());
    }
    qDebug() << "WARNING: not valid input parameter, who knows which one :)";
    return GAInput();
}
