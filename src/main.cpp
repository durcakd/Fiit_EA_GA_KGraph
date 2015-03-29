#include "mainwindow.h"
#include <QApplication>


#include <QDebug>
#include <util.h>
#include "graph.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    Graph::init(5);

    Graph g1;
    Graph g2;
    g1.generateNodes();
    g2.generateNodes();

    //g1.calcFitness();
    qDebug() << g1.toString();
    qDebug() << g2.toString();
    qDebug() << "----------------";

    Graph *g3 = new Graph;
    Graph *g4 = new Graph;

    g1.crossover(g2, *g3, *g4);

    qDebug() << g3->toString();
    qDebug() << g4->toString();
    qDebug() << "----------------";

    return app.exec();
}

