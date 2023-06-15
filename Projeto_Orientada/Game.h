#ifndef GAME_H
#define GAME_H

#include "Button.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <QGraphicsView.h>
#include <QMouseEvent>
#include <QSignalMapper>


class Game: public QGraphicsView{
    Q_OBJECT

    //constructor
    Game(QWidget* parent=NULL);
public:
    //public methods
    void displayMainMenu();
    void displayEndScreen();
    Player* getWhosTurn();
    void setWhosTurn(Player* player);
    Player* getWinner();
    void setWinner(Player* player);
    void pickUpCard(Card* card);
    void placeCard(Card* cardToReplace);
    void nextPlayersTurn();
    void skipOneTurn();
    void addPlayer(Player* player);
    void drawCards();
    void setPlayerOrder(bool b);
    bool getPlayerOrder();
    void setMais2Mais4flag(int i);
    int getMais2Mais4Flag();
    bool getUNOButtonPressed();
    void setUNOButtonNotPressed();
    int getNumberOfPlayers();
    void start();

    // eventes
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);

    //public atributes
    QGraphicsScene* scene;
    Card* cardToPlace;
    QPointF originalPos;

    static Game* getInstance();

public slots:
    void setUNOButtonPressed();
    void displaySecondMenu();
    void setNumberOfPlayerToTow();
    void setNumberOfPlayerToThree();
    void setNumberOfPlayerToFour();

private:
    // private methods
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
    void creatInitialCards();

    // private atributes
    Button* UNOButton;
    bool UNOButtonPressed;
    int mais2mais4flag;
    bool playerOrder;
    Deck* deck;
    int numberOfPlayers;
    QList<Player* > playerList;
    Player* whosTurn_;
    Player* winner;
    QGraphicsTextItem* whosTurnText;
    static Game *_instance;
};

#endif // GAME_H
