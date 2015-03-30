#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    antialiased = true;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    edgeList = NULL;
}

QSize RenderArea::minimumSizeHint() const {
    return QSize(200, 200);
}

QSize RenderArea::sizeHint() const {
    return QSize(600, 600);
}

void RenderArea::setPen(const QPen &pen) {
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush) {
    this->brush = brush;
    update();
}

void RenderArea::setGraphEdges(Graph *g) {
    double maxx, maxy;
    g->getExtremNodesCords(minx, miny, maxx, maxy);
    maxd = maxx-minx > maxy-miny ? maxx-minx : maxy-miny;

    delete edgeList;
    edgeList = new std::vector<Edge*>();

    g->calculateEdges( *edgeList);
}



void RenderArea::paintEvent(QPaintEvent * /* event */) {
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, 80, 60);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);


    for (int x = 0; x < width(); x += 100) {
        for (int y = 0; y < height(); y += 100) {
            painter.save();
            painter.translate(x, y);

            if (NULL != edgeList) {
                int minwind = width() < height() ? width():height();
                double coef = ((double)minwind)/maxd;

                std::vector<Edge*>::const_iterator it=edgeList->cbegin();
                for ( ; it!= edgeList->cend(); it++) {
                    const Edge &e = **it;
                    int x1 = ((e.x1)-minx) * coef;
                    int y1 = ((e.y1)-miny) * coef;
                    int x2 = ((e.x2)-minx) * coef;
                    int y2 = ((e.y2)-miny) * coef;
                    painter.drawLine(x1,y1,x2,y2);

                    // Points:
                    painter.drawPoint(x1,y1);
                    painter.drawPoint(x2,y2);
                }
            }

            painter.restore();
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
