#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Deck: public QGraphicsPixmapItem{
public:
    // constructor
    Deck(QGraphicsItem* parent=NULL);

    // public methods
    void deckSuffle();


    // getter
    Card* getCardFromDeck();

    //event
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    QPainterPath deckShape;
    std::vector<Card*> deckCardArr;
    QList<Card*> tempCardArr;
};

#endif // DECK_H
