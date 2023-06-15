#ifndef CARD_H
#define CARD_H

#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Card: public QGraphicsRectItem{
public:
    enum Ranks {ZERO, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, BLOQUEIO, REVERSO, MAIS_2, MAIS_4, WILD};
    enum Colors {VERMELHO, AMARELO, AZUL, VERDE, SPECIAL};

    // constructors
    Card(Ranks RANK = ZERO, Colors COLOR = VERMELHO, QGraphicsItem* parent=NULL);

    // getters
    Ranks getRank();
    Colors getColor();
    bool getIsPlaced();
    bool getIsLiftable();

    // setters
    void setBackCardOpacity(int i);
    void setIsLiftable(bool b);
    void setIsPlaced(bool b);

    // event
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QGraphicsPixmapItem* backCardImage;
    QGraphicsPixmapItem* cardFace;
    bool liftable;
    bool isPlaced;
    Ranks rank;
    Colors color;
};

#endif // CARD_H
