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

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

public slots:
    void runTest();

private:
    QGridLayout *createParamLayout();
    QGroupBox *createFirstExclusiveGroup();
    GAInput getParams();


    QPushButton *runTestPB;
    QLabel promtL1;
    QLabel promtL2;
    QLabel promtL3;

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

    QRadioButton *ga1RB;
    QRadioButton *ga2RB;
    QRadioButton *ga3RB;
/*
cNodes
cTest
cGen
cPop
sElit
sCross
sMut
sNew
*/
};

#endif // MAINWINDOW_H
