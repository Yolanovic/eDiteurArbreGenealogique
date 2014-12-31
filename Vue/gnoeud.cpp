#include "gnoeud.h"
#include <QPaintEvent>
#include "qpainter.h"



gNoeud::~gNoeud()
{

}
gNoeud::gNoeud(float a, float b, float c, float d):QGraphicsEllipseItem (a,b,c,d){
    text = QString::fromStdString("hehehehe");
}
gNoeud::gNoeud(float a, float b, float c, float d,QString txt):QGraphicsEllipseItem (a,b,c,d){
    text = txt;
}
void gNoeud::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QGraphicsEllipseItem::paint(painter,option,widget);
    painter->drawText(this->rect(),Qt::AlignCenter,text);
    this->setBrush(QBrush(Qt::white));
    this->brush();
}


