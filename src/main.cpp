#include <QDebug>

#include "mainwindow.h"
#include <QApplication>

#include <util.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();



    const int nrolls=1000000;  // number of experiments
    const int nstars=100;
    int p[10]={};
    Util::get()->setSigma(2.0);
    Util::get()->setMean(5.0);
    for(int i=0; i<nrolls; i++) {
        double number = Util::get()->ud()*10.0;
        //qDebug() << int(number) << "  "<< number;
        if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
    }
    qDebug() << "normal_distribution (5.0,2.0):";
    for (int i=0; i<10; ++i) {
      qDebug() << i << "-" << (i+1) << ": "\
               //<< p[i]*nstars/nrolls<<" "
               << QString(p[i]*nstars/nrolls,'*');
    }



    return app.exec();
}

