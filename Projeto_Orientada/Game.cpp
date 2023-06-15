#include "Game.h"
#include "Button.h"
#include "Deck.h"
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMovie>
#include <QLabel>

Game* Game::_instance = nullptr;

Game* Game::getInstance(){
    if(_instance == nullptr)
        _instance = new Game();

    return _instance;
}

Game::Game(QWidget *parent)
{
    // setup the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,770);

    // steup the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);

    // inicializer variáveis
    cardToPlace = NULL;
}

void Game::start(){
    scene->clear();
    drawGUI();

    //cria deck e posiciona
    deck = new Deck();
    scene->addItem(deck);
    deck->setPos(570,250);
    //deck->setScale(1);
    deck->deckSuffle();

    // define e desenha a carta inicial
    Card* startingCard = deck->getCardFromDeck();
    startingCard->setPos(330, 250);
    startingCard->setIsPlaced(true);
    startingCard->setIsLiftable(false);
    startingCard->setBackCardOpacity(0);
    scene->addItem(startingCard);

    //cria cada jogador e posiciona o texto de cada jogador
    for(int i=0; i<numberOfPlayers; i++){
        Player* player = new Player(QString("PLAYER")+QString::number(i+1));
        player->setTimeToPlay(i);
        switch (i) {
        case 0:
            player->setPos(500, 618);
            break;
        case 1:
            player->setPos(874, 384);
            player->setRotation(-90);
            break;
        case 2:
            player->setPos(500, 130);
            break;
        case 3:
            player->setPos(153, 384);
            player->setRotation(90);
            break;
        }
        scene->addItem(player);
        addPlayer(player);
    }
    //cria as cartas iniciais de cada jogadro comprando do deck e desenha as cartas
    creatInitialCards();
    drawCards();

    // define o player 1 como primeiro a jogar e posiciona o texto de quem joga e define a ordem de jogada
    setPlayerOrder(false);
    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(playerList[0]);
    whosTurnText->setPos(463,150);
    scene->addItem(whosTurnText);

    // inicia a flag do +2 e +4 como zero
    setMais2Mais4flag(0);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // desenha um painel onde ficara as hands de cada player
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::drawGUI(){
    // desenha os paineis
    drawPanel(0,0,1024,800,Qt::white, 0.3);
    drawPanel(150,150,1024-300,768-300,Qt::white, 1);
    drawPanel(150,150,1024-300,768-300,Qt::gray, 0.4);

    QGraphicsPixmapItem* board = new QGraphicsPixmapItem();
    QPixmap boardImage(":/resources/img/uno_board_image.png");
    board->setPixmap(boardImage);
    board->setPos(0,0);
    scene->addItem(board);

    UNOButton = new Button(QString("UNO!"));
    int bxPos = this->width()/2 - UNOButton->boundingRect().width()/2;
    int byPos = 540;
    UNOButton->setPos(bxPos, byPos);
    connect(UNOButton, SIGNAL(clicked()), this, SLOT(setUNOButtonPressed()));
    UNOButton->setUNObuttonOpacity(1);
    scene->addItem(UNOButton);
}

void Game::creatInitialCards(){
    // cria cartas para o player 1
    for (int i=0; i<playerList.size(); i++){
        for(int n=0; n < 7; n++){
            playerList[i]->addCardToHand(deck->getCardFromDeck());
        }
    }
}

void Game::drawCards(){
    // essa função desnha as (5) cartas iniciais de cada jogador
    if(playerList.size() > 0){
        for(int i=0; i < playerList[0]->getHand().size(); i++){
            Card* card = playerList[0]->getHand()[i];
            card->setPos(170+30*i,650);
            scene->addItem(card);
        }
    }

    if(playerList.size() > 1){
        for(int i=0; i < playerList[1]->getHand().size(); i++){
            Card* card = playerList[1]->getHand()[i];
            card->setPos(874+30,600-30*i);
            card->setRotation(-90);
            scene->addItem(card);
        }
    }

    if(playerList.size() > 2){
        for(int i=0; i < playerList[2]->getHand().size(); i++){
            Card* card = playerList[2]->getHand()[i];
            card->setPos(850-30*i,150-30);
            card->setRotation(180);
            scene->addItem(card);
        }
    }

    if(playerList.size() > 3){
        for(int i=0; i < playerList[3]->getHand().size(); i++){
            Card* card = playerList[3]->getHand()[i];
            card->setPos(150-30,185+30*i);
            card->setRotation(90);
            scene->addItem(card);
        }
    }
}

void Game::setPlayerOrder(bool b){
    playerOrder = b;
}

bool Game::getPlayerOrder(){
    return playerOrder;
}

void Game::setMais2Mais4flag(int i){
    mais2mais4flag = i;
}

int Game::getMais2Mais4Flag(){
    return mais2mais4flag;
}

void Game::setUNOButtonPressed(){
    UNOButtonPressed = true;
}

bool Game::getUNOButtonPressed(){
    return UNOButtonPressed;
}

void Game::setUNOButtonNotPressed(){
    UNOButtonPressed = false;
}

void Game::setNumberOfPlayerToTow(){
    numberOfPlayers = 2;
    start();
}

void Game::setNumberOfPlayerToThree(){
    numberOfPlayers = 3;
    start();
}

void Game::setNumberOfPlayerToFour(){
    numberOfPlayers = 4;
    start();
}

int Game::getNumberOfPlayers(){
    return numberOfPlayers;
}

void Game::displayMainMenu(){
    drawPanel(0,0,1024,768,Qt::black, 1);

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("UNO"));
    QFont titleFont("comic sans", 70);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 200;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    QGraphicsPixmapItem* logo = new QGraphicsPixmapItem();
    QPixmap logoImage(":/resources/img/logo2.png");
    logo->setPixmap(logoImage);
    logo->setPos(-220,-50);
    logo->setScale(0.6);
    scene->addItem(logo);

    Button* playButton = new Button(QString("PLAY"));
    int bxPos = 275;
    int byPos = 650;
    playButton->setPos(bxPos, byPos);
    connect(playButton, SIGNAL(clicked()), this, SLOT(displaySecondMenu()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("QUIT"));
    int qxPos = 575;
    int qyPos = 650;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

void Game::displaySecondMenu(){
    scene->clear();

    drawPanel(0,0,1024,768,Qt::black, 1);

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("UNO"));
    QFont titleFont("comic sans", 70);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 200;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    QGraphicsPixmapItem* logo = new QGraphicsPixmapItem();
    QPixmap logoImage(":/resources/img/UNO_Logo.svg.png");
    logo->setPixmap(logoImage);
    logo->setPos(265,70);
    logo->setScale(0.4);
    scene->addItem(logo);

    Button* towPlayers = new Button(QString("2 PLAYERS"));
    int towPlayersxPos = this->width()/2 - towPlayers->boundingRect().width()/2;
    int towPlayersyPos = 425;
    towPlayers->setPos(towPlayersxPos, towPlayersyPos);
    connect(towPlayers, SIGNAL(clicked()), this, SLOT(setNumberOfPlayerToTow()));
    scene->addItem(towPlayers);

    Button* threePlayers = new Button(QString("3 PLAYERS"));
    int threePlayersxPos = this->width()/2 - threePlayers->boundingRect().width()/2;
    int threePlayersyPos = 500;
    threePlayers->setPos(threePlayersxPos, threePlayersyPos);
    connect(threePlayers, SIGNAL(clicked()), this, SLOT(setNumberOfPlayerToThree()));
    scene->addItem(threePlayers);

    Button* fourPlayers = new Button(QString("4 PLAYERS"));
    int fourPlayersxPos = this->width()/2 - fourPlayers->boundingRect().width()/2;
    int fourPlayersyPos = 575;
    fourPlayers->setPos(fourPlayersxPos, fourPlayersyPos);
    connect(fourPlayers, SIGNAL(clicked()), this, SLOT(setNumberOfPlayerToFour()));
    scene->addItem(fourPlayers);
}

void Game::displayEndScreen(){
    drawPanel(0,0,1024,768,Qt::gray, 0.5);

    setWinner(playerList[0]); // inicializa winner com player1

    for(int i=0; i<playerList.size(); i++){
        if(winner->getHand().size() > playerList[i]->getHand().size()){
            setWinner(playerList[i]);
        }
    }

    QGraphicsTextItem* winnerText = new QGraphicsTextItem();
    QFont winnerTextFont("comic sans", 50);
    winnerText->setFont(winnerTextFont);
    winnerText->setPlainText(QString("WINNER:") + winner->getName());
    winnerText->setPos(240, 360);
    scene->addItem(winnerText);

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("GAME OVER"));
    QFont titleFont("comic sans", 70);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 200;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);
}

Player* Game::getWhosTurn(){
    return whosTurn_;
}

void Game::setWhosTurn(Player* player){
    // altera a vez de quem joga e altera quais cartas podem ser levantadas
    for(int i=0; i < playerList.size(); i++){
        for(int n=0; n < playerList[i]->getHand().size(); n++){
            playerList[i]->getHand()[n]->setIsLiftable(false);
            playerList[i]->getHand()[n]->setBackCardOpacity(1);
        }
    }
    for(int i=0; i < player->getHand().size(); i++){
        player->getHand()[i]->setIsLiftable(true);
        player->getHand()[i]->setBackCardOpacity(0);
    }
    whosTurnText->setPlainText(QString("Whos turn: ") + player->getName());
    whosTurn_ = player;
}

Player *Game::getWinner(){
    return winner;
}

void Game::setWinner(Player *player){
    winner = player;
}

void Game::pickUpCard(Card *card){
    // levantar a carta especificada
    if(card->getIsLiftable() == true && cardToPlace == NULL){
        cardToPlace = card;
        originalPos = card->pos();
        return;
    }
}

void Game::placeCard(Card *cardToReplace){
    // troca a carta que está colocada(cardToReplace) com (cardToPlace) seguindo as regras do jogo
    //UNOButton->setAvailable(false);

    // se a carta tiver a mesma cor ou o mesmo rank
    if(cardToReplace->getColor() == cardToPlace->getColor() ||
        cardToReplace->getRank() == cardToPlace->getRank() ||
        cardToReplace->getColor() == Card::SPECIAL ||
        cardToPlace->getColor() == Card::SPECIAL){
        if(mais2mais4flag == 0){
            // seta a posição de cardToPlace para a pos cardToReplace
            cardToPlace->setPos(cardToReplace->pos());
            // remove cardToReplace
            scene->removeItem(cardToReplace);
            // seta cardToPlace como colocado
            cardToPlace->setIsPlaced(true);
            // seta cardToPlane como not liftable
            cardToPlace->setIsLiftable(false);
            // remove cardToPlace da mão do jogador
            whosTurn_->removeCardFromHand(cardToPlace);
            // checa vencedor
            if(getWhosTurn()->getHand().size() == 0){
                displayEndScreen();
            }
            // ceca se o botão uno foi apertado e se está com uma carta
            if(getWhosTurn()->getHand().size() == 1){
                if(!getUNOButtonPressed()){
                    getWhosTurn()->addCardToHand(deck->getCardFromDeck());
                    getWhosTurn()->addCardToHand(deck->getCardFromDeck());
                    getWhosTurn()->addCardToHand(deck->getCardFromDeck());
                    getWhosTurn()->addCardToHand(deck->getCardFromDeck());
                    drawCards();
                }
            }
            setUNOButtonNotPressed();
            // passa a vez
            if(cardToPlace->getRank() == Card::BLOQUEIO){
                skipOneTurn();
            }
            else if(cardToPlace->getRank() == Card::REVERSO){
                setPlayerOrder(!playerOrder);
                nextPlayersTurn();
            }
            else if(cardToPlace->getRank() == Card::MAIS_2){
                setMais2Mais4flag(2);
                nextPlayersTurn();
            }
            else if(cardToPlace->getRank() == Card::MAIS_4){
                setMais2Mais4flag(4);
                nextPlayersTurn();
            }
            else{
                nextPlayersTurn();
            }
            // apaga cardToPlace
            cardToPlace = NULL;
        }
    }
}

void Game::nextPlayersTurn(){
    if(playerOrder == true){
        if(getWhosTurn()->getTimeToPlay() == 0){
            setWhosTurn(playerList[playerList.size()-1]);
        }
        else
        {
           setWhosTurn(playerList[getWhosTurn()->getTimeToPlay()-1]);
        }
    }
    if(playerOrder == false){
        if(getWhosTurn()->getTimeToPlay() == playerList.size()-1){
           setWhosTurn(playerList[0]);
        }
        else
        {
            setWhosTurn(playerList[(getWhosTurn()->getTimeToPlay()+1)]);
        }
    }
}

void Game::skipOneTurn(){
    if(playerOrder == true){
        if(getWhosTurn()->getTimeToPlay() == 0){
           setWhosTurn(playerList[playerList.size()-2]);
        }
        else if(getWhosTurn()->getTimeToPlay() == 1){
           setWhosTurn(playerList[playerList.size()-1]);
        }
        else
        {
           setWhosTurn(playerList[getWhosTurn()->getTimeToPlay()-2]);
        }
    }
    if(playerOrder == false){
        if(getWhosTurn()->getTimeToPlay() == playerList.size()-1){
           setWhosTurn(playerList[1]);
        }
        else if(getWhosTurn()->getTimeToPlay() == playerList.size()-2){
           setWhosTurn(playerList[0]);
        }
        else
        {
           setWhosTurn(playerList[(getWhosTurn()->getTimeToPlay()+2)]);
        }
    }
}

void Game::addPlayer(Player * player){
    playerList.append(player);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    // if cardToPlace, então segue o mouse
    if(cardToPlace){
        cardToPlace->setRotation(0);
        QPoint mousePos = event->pos();
        int xOffset = 5;
        cardToPlace->setPos(mousePos.x() + xOffset, mousePos.y());
    }

    QGraphicsView::mouseMoveEvent(event);
}

void Game::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::RightButton){
        if(cardToPlace){
           cardToPlace->setPos(originalPos);
           switch (getWhosTurn()->getTimeToPlay()) {
           case 0:
                cardToPlace->setRotation(0);
                break;
           case 1:
                cardToPlace->setRotation(-90);
                break;
           case 2:
                cardToPlace->setRotation(180);
                break;
           case 3:
                cardToPlace->setRotation(90);
                break;
           }
           cardToPlace = NULL;
           return;
        }
    }
    QGraphicsView::mousePressEvent(event);
}
