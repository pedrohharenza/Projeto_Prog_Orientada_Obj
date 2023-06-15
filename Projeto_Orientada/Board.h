#ifndef BOARD_H
#define BOARD_H

#include "Card.h"
#include "Deck.h"

class Board{
public:
    // constructors
    Board();

    // getters
    Card* getCard();

    // seter
    void setCardPtr(Card* card);

    //public methods
    void placeCard(int x, int y);

private:
    Card* cardPtr;
};

#endif // BOARD_H
