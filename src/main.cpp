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

    Graph::init(3);

    Graph graph;
    graph.generateNodes();
    graph.calcFitness();
    qDebug() << graph.toString();
    qDebug() << "----------------";


    return app.exec();
}

