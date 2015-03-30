#include "grapharea.h"

#include <QPainter>

GraphArea::GraphArea(QWidget *parent)
    : QWidget(parent)
{
    antialiased = true;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    edgeList = NULL;
}

QSize GraphArea::minimumSizeHint() const {
    return QSize(200, 200);
}

QSize GraphArea::sizeHint() const {
    return QSize(800, 600);
}

void GraphArea::setGraphEdges(Graph *g) {
    if (NULL != g) {
        double maxx, maxy;
        g->getExtremNodesCords(minx, miny, maxx, maxy);
        maxd = maxx-minx > maxy-miny ? maxx-minx : maxy-miny;

        delete edgeList;
        edgeList = new std::vector<Edge*>();

        g->calculateEdges( *edgeList);
    }
    update();
}

void GraphArea::paintEvent(QPaintEvent * /* event */) {

    QPainter painter(this);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

    if (NULL != edgeList) {
        painter.save();
        int minwind = width() < height() ? width():height();
        double coef = ((double)minwind-20)/maxd;
        painter.translate((width()-minwind)/2+10, (height()-minwind)/2+10);


        QPen         pointPen(Qt::black, 4, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
        QPen          edgePen(Qt::blue,  1, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);
        QPen interceptEdgePen(Qt::red,   1, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin);

        std::vector<Edge*>::const_iterator it=edgeList->cbegin();
        for ( ; it!= edgeList->cend(); it++) {
            const Edge &e = **it;
            int x1 = (((e.x1)-minx) * coef);
            int y1 = (((e.y1)-miny) * coef);
            int x2 = (((e.x2)-minx) * coef);
            int y2 = (((e.y2)-miny) * coef);
            painter.setPen( e.isIntercepted ? interceptEdgePen : edgePen );
            painter.drawLine(x1,y1,x2,y2);

            // Points:
            painter.setPen(pointPen );
            painter.drawPoint(x1,y1);
            painter.drawPoint(x2,y2);
        }
        painter.restore();
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
