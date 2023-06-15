#include "Deck.h"
#include "Game.h"
#include <QPixmap>

extern Game* game;

Deck::Deck(QGraphicsItem *parent): deckCardArr(){

    setPixmap(QPixmap(":/resources/img/uno_card_back_correct_size.png"));

    QVector<QPointF> deckPoints;
    deckPoints << QPointF(0,0) << QPointF (0,3) << QPointF(2,3) << QPointF (2,0);

    int SCALE_BY = 60;
    for (size_t i=0, n = deckPoints.size(); i < n; i++){
        deckPoints[i] *= SCALE_BY;
    }

    // cria o poligono com o tamanho correto
    QPolygonF deck_polygon(deckPoints);

    // desenha o poligono
    /*
    setPolygon(deck_polygon);
    QBrush whitebrush;
    whitebrush.setStyle(Qt::SolidPattern);
    whitebrush.setColor(Qt::white);
    setBrush(whitebrush);

    QGraphicsRectItem* blackBox = new QGraphicsRectItem(0, 0, 120-10, 180-10, this);
    blackBox->setPos(5,5);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QColor cor(33, 33, 36);
    brush.setColor(cor);
    blackBox->setBrush(brush);

    QFont font("comic sans", 40);
    QColor textColor(Qt::yellow);

    QGraphicsTextItem* deckText = new QGraphicsTextItem("UNO", this);
    deckText->setFont(font);
    deckText->setRotation(-45);
    deckText->setPos(-5,100);

    QTextOption textOption;
    deckText->setDefaultTextColor(textColor);
   */

    // adicionar mais imagens de cartas para parecer um deck real
    QGraphicsPixmapItem* moreCards = new QGraphicsPixmapItem(QPixmap(":/resources/img/uno_card_back_correct_size.png"), this);
    moreCards->setPos(7,0);
    QGraphicsPixmapItem* moreCards1 = new QGraphicsPixmapItem(QPixmap(":/resources/img/uno_card_back_correct_size.png"), this);
    moreCards1->setPos(14,0);
    QGraphicsPixmapItem* moreCards2 = new QGraphicsPixmapItem(QPixmap(":/resources/img/uno_card_back_correct_size.png"), this);
    moreCards2->setPos(21,0);
    QGraphicsPixmapItem* moreCards3 = new QGraphicsPixmapItem(QPixmap(":/resources/img/uno_card_back_correct_size.png"), this);
    moreCards3->setPos(28,0);

    // cria 2 cartas de cada cor e cada e valor de zero até +2
    for(int i=0; i<2; i++){
        for(int color = Card::VERMELHO; color <= Card::VERDE; ++color) {
            for(int rank = Card::ZERO; rank <= Card::MAIS_2; ++rank) {
                Card::Ranks cardRank = static_cast<Card::Ranks>(rank);
                Card::Colors cardColor = static_cast<Card::Colors>(color);
                deckCardArr.push_back(new Card(cardRank, cardColor, this));
            }
        }
    }
    // cria wild card e +4
    for(int i=0; i<4; i++){
        deckCardArr.push_back(new Card(Card::MAIS_4, Card::SPECIAL, this));
        deckCardArr.push_back(new Card(Card::WILD, Card::SPECIAL, this));
    }
}

void Deck::deckSuffle(){
    std::random_shuffle(deckCardArr.begin(), deckCardArr.end());
}

Card* Deck::getCardFromDeck(){
        Card* card = deckCardArr.back();
        deckCardArr.pop_back();
        return card;
}

void Deck::mousePressEvent(QGraphicsSceneMouseEvent *event){
        if(deckCardArr.size() == 0){
            Game::getInstance()->displayEndScreen();
        }
        else
        {
            Card* card = getCardFromDeck();
            card->setIsLiftable(true);
            card->setIsPlaced(false);
            card->setBackCardOpacity(0);
            Game::getInstance()->getWhosTurn()->addCardToHand(card);
            Game::getInstance()->drawCards();
            if(Game::getInstance()->getMais2Mais4Flag() > 0){
            Game::getInstance()->setMais2Mais4flag(Game::getInstance()->getMais2Mais4Flag()-1);
            }
        }

}



