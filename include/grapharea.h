#ifndef GRAPHAREA_H
#define GRAPHAREA_H

#include <QWidget>
#include "graph.h"
#include "edge.h"
#include <vector>

class GraphArea : public QWidget
{
    Q_OBJECT

public:
    GraphArea(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void setGraphEdges(Graph *g);

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool antialiased;
    double minx;
    double miny;
    double maxd;
    std::vector<Edge*> *edgeList;
};

#endif
