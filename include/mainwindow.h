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
#include "gainput.h"
#include "gaoutput.h"
#include <QRadioButton>
#include <QGroupBox>

#include "grapharea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

public slots:
    void runTest();
    void cNodesLEChanged(QString text);
    void bUseProbMutChanged(bool checked);
    void bUseAutoProbChanged(bool checked);

private:
    QGridLayout *createParamLayout();
    GAInput getParams();


    GraphArea graphArea;

    QPushButton *runTestPB;
    QLabel promtL1;
    QLabel promtL2;
    QLabel promtL3;
    QLabel promtL4;

    GAInput input;
    GAOutput output;
    bool tested;

    QLineEdit *cNodesLE;
    QLineEdit *cTestLE;
    QLineEdit *cGenLE;
    QLineEdit *cPopLE;
    QLineEdit *sElitLE;
    QLineEdit *sCrossLE;
    QLineEdit *sMutLE;
    QLineEdit *sNewLE;
    QLineEdit *sTourCrossLE;
    QLineEdit *sTourMutLE;
    QLineEdit *sMutProbLE;
    QCheckBox *bUseProbMutCB;
    QCheckBox *bUseAutoProbCB;

/*
cNodes
cTest
cGen
cPop
sElit
sCross
sMut
sNew
sTourCross
sTourMut
sMutProb
bUseProbMut
bUseAutoProb
*/
};

#endif // MAINWINDOW_H
