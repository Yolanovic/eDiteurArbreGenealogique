#ifndef GNOEUD_H
#define GNOEUD_H
#include<QGraphicsEllipseItem>



class gNoeud : public QGraphicsEllipseItem
{
public:
    gNoeud(float a, float b, float c, float d);
     gNoeud(float a, float b, float c, float d, QString qs);
    ~gNoeud();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QString text;
};

#endif // GNOEUD_H
