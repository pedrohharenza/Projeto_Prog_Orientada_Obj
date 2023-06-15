#include "Card.h"
#include "Game.h"
#include "qbrush.h"

Card::Card(Ranks RANK, Colors COLOR, QGraphicsItem *parent):rank(RANK), color(COLOR){
    /*
    QVector<QPointF> cardPoints;
    cardPoints << QPointF(0,0) << QPointF (0,3) << QPointF(2,3) << QPointF (2,0);

    int SCALE_BY = 59;
    for (size_t i=0, n = cardPoints.size(); i < n; i++){
        cardPoints[i] *= SCALE_BY;
    }

    // cria o poligono com o tamanho correto
    QPolygonF card(cardPoints);

    // desenha o poligono
    //setPolygon(card);
*/
    // desenha retangulo
    setRect(0,0,120,180);

    // inicializar
    setAcceptHoverEvents(true);
    isPlaced = false;

    // cores
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(COLOR == 0){
        brush.setColor(Qt::red);
    }
    else if(COLOR == 1){
        brush.setColor(Qt::yellow);
    }
    else if(COLOR == 2){
        QColor cor(0, 128, 255);
        brush.setColor(cor);
    }
    else if(COLOR == 3){
        brush.setColor(Qt::green);
    }
    //BLOQUEIO, REVERSO, MAIS_2, MAIS_4, WILD
    if (RANK == BLOQUEIO){
        QGraphicsTextItem* text = new QGraphicsTextItem(QString("BLOQUEIO"), this);
        text->setPos(25,3);
        text->setRotation(90);
    }
    if (RANK == REVERSO){
        QGraphicsTextItem* text = new QGraphicsTextItem(QString("REVERSO"), this);
        text->setPos(25,3);
        text->setRotation(90);
    }
    if (RANK == MAIS_2){
        QGraphicsTextItem* text = new QGraphicsTextItem(QString("+2"), this);
        text->setPos(9,3);
    }
    if (RANK == MAIS_4){
        brush.setColor(Qt::gray);
        QGraphicsTextItem* text = new QGraphicsTextItem(QString("+4"), this);
        text->setPos(9,3);

    }
    if (RANK == WILD){
        brush.setColor(Qt::gray);
        QGraphicsTextItem* text = new QGraphicsTextItem(QString("WILD"), this);
        text->setPos(25,3);
        text->setRotation(90);
    }
    setBrush(brush);

    if (RANK < BLOQUEIO){
        QGraphicsTextItem* rank = new QGraphicsTextItem(QString::number(RANK), this);
        rank->setPos(10,3);
    }

    // card images
    if (RANK == WILD){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/wild_card.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == MAIS_4){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/mais4.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == REVERSO && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/reverse_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == REVERSO && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/reverse_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == REVERSO && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/reverse_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == REVERSO && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/reverse_verde.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == BLOQUEIO && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/bloqueio_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == BLOQUEIO && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/bloqueio_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == BLOQUEIO && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/bloqueio_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == BLOQUEIO && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/bloqueio_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == MAIS_2 && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/mais2_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == MAIS_2 && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/mais2_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == MAIS_2 && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/mais2_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == MAIS_2 && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/mais2_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == ZERO && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/0_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == ZERO && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/0_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == ZERO && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/0_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == ZERO && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/0_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == UM && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/1_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == UM && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/1_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == UM && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/1_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == UM && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/1_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == DOIS && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/2_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == DOIS && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/2_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == DOIS && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/2_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == DOIS && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/2_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == TRES && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/3_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == TRES && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/3_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == TRES && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/3_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == TRES && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/3_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == QUATRO && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/4_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == QUATRO && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/4_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == QUATRO && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/4_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == QUATRO && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/4_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == CINCO && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/5_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == CINCO && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/5_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == CINCO && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/5_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == CINCO && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/5_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == SEIS && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/6_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == SEIS && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/6_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == SEIS && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/6_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == SEIS && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/6_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == SETE && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/7_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == SETE && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/7_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == SETE && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/7_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == SETE && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/7_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == OITO && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/8_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == OITO && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/8_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == OITO && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/8_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == OITO && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/8_verde.png"), this);
        cardFace->setPos(-6,-10);
    }

    if (RANK == NOVE && COLOR == VERMELHO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/9_vermelho.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == NOVE && COLOR == AZUL){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/9_azul.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == NOVE && COLOR == AMARELO){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/9_amarelo.png"), this);
        cardFace->setPos(-6,-10);
    }
    if (RANK == NOVE && COLOR == VERDE){
        cardFace = new QGraphicsPixmapItem(QPixmap(":/resources/img/9_verde.png"), this);
        cardFace->setPos(-6,-10);
    }


    // imagem
    backCardImage = new QGraphicsPixmapItem(QPixmap(":/resources/img/uno_card_back_correct_size.png"), this);
    backCardImage->setPos(-6,-10);
}

Card::Ranks Card::getRank(){
    return rank;
}

Card::Colors Card::getColor(){
    return color;
}

bool Card::getIsPlaced(){
    return isPlaced;
}

bool Card::getIsLiftable(){
    return liftable;
}

void Card::setBackCardOpacity(int i){
    backCardImage->setOpacity(i);
}

void Card::setIsLiftable(bool b){
    liftable = b;
}

void Card::setIsPlaced(bool b){
    isPlaced = b;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // se não tiver colocado levantar
    if(getIsPlaced() == false && liftable){
        Game::getInstance()->pickUpCard(this);
    }

    //se está colocado e existe carta para colocar trocar
    else if(getIsPlaced() == true && Game::getInstance()->cardToPlace != NULL){
        Game::getInstance()->placeCard(this);
    }
}

void Card::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(liftable){
        cardFace->setPos(-6,-60);
    }
}

void Card::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(liftable){
        cardFace->setPos(-6,-10);
    }
}
