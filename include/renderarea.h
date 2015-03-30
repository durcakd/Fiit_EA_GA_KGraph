#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "graph.h"
#include "edge.h"
#include <vector>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void setGraphEdges(Graph *g);

public slots:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPen pen;
    QBrush brush;
    bool antialiased;

    double minx;
    double miny;
    double maxd;

    std::vector<Edge*> *edgeList;
};

#endif // RENDERAREA_H
