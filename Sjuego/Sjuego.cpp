/*Copyright 2015 Francisco Lorente Ruiz.

    This file is part of Space Invaders Qt.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>. 
*/



#include "Sjuego.h"

Sjuego::Sjuego(QWidget *parent) :QWidget(parent)
{
    ///INICIAR VARIABLES.
    view = new QGraphicsView();
    escena = new QGraphicsScene();

    hlayout = new QHBoxLayout();
    vlayout = new QVBoxLayout();

    puntosLabel=new QLabel();
    vidasLabel=new QLabel();
    nivelLabel=new QLabel();

    pausaAction=new QAction("Pausa", this);

    timerRefresh = new QTimer();

    nave = new Snave();
    balas = new Sbalas();


    ///CONFIGURACIÓN DE QGRAPHICSVIEW.
    view->setScene(escena);
    view->setSceneRect(0, 0, SI::ancho, SI::alto);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    escena->addItem(nave);
    escuadron.cargar(escena);
    escena->addItem(balas);


    ///CONFIGURACIÓN DE LOS LABEL.
    puntosLabel->setAlignment(Qt::AlignCenter);
    puntosLabel->setMaximumHeight(20);
    vidasLabel->setAlignment(Qt::AlignCenter);
    vidasLabel->setMaximumHeight(20);
    nivelLabel->setAlignment(Qt::AlignCenter);
    nivelLabel->setMaximumHeight(20);


    ///CONFIGURACIÓN DE LOS LAYOUTS.
    hlayout->setContentsMargins(0, 0, 0, 0);
    vlayout->setContentsMargins(0, 0, 0, 0);
    hlayout->setSpacing(0);
    vlayout->setSpacing(0);
    hlayout->addWidget(puntosLabel);
    hlayout->addWidget(vidasLabel);
    hlayout->addWidget(nivelLabel);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(view);
    setLayout(vlayout);


    ///CONFIGURACIÓN DE LOS ACTIONS.
    addAction(pausaAction);
    pausaAction->setShortcut(Qt::Key_P);
    connect(pausaAction, SIGNAL(triggered()), this, SLOT(pausar()));


    ///TIMER.
    connect(timerRefresh, SIGNAL(timeout()), this, SLOT(actualizar()));
    iniciar();


    ///GENERAL.
    definirStylesSheets();
    setFocusPolicy(Qt::StrongFocus);
    key_down=false;
    key_up=false;
    key_left=false;
    key_right=false;
    puntos=0;
    vidas=3;
}

void Sjuego::keyPressEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Space) key_space=true;
    if(event->key()==Qt::Key_Up) key_up=true;
    if(event->key()==Qt::Key_Down) key_down=true;
    if(event->key()==Qt::Key_Right) key_right=true;
    if(event->key()==Qt::Key_Left) key_left=true;
}

void Sjuego::keyReleaseEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Space) key_space=false;
    if(event->key()==Qt::Key_Up) key_up=false;
    if(event->key()==Qt::Key_Down) key_down=false;
    if(event->key()==Qt::Key_Right) key_right=false;
    if(event->key()==Qt::Key_Left) key_left=false;
}

void Sjuego::iniciar()
{
    timerRefresh->start(20);
}

void Sjuego::actualizar()
{
    QString texto;

    if(escuadron.destruido())
    {
        nave->siguienteNivel();
        puntos+=50;
    }

    if(key_up) nave->moveBy(0, -1); //No tocar. Si se quiere modificar su velocidad, ajustar en la clase Snave.
    if(key_down) nave->moveBy(0, 1);
    if(key_right) nave->moveBy(1, 0);
    if(key_left) nave->moveBy(-1, 0);
    if(key_space) balas->disparar(nave->x()+nave->anchura()/2, nave->y()+2);

    escuadron.moveBy();
    balas->moveBy();

    choqueAlienBala();
    choqueAlienNave();
    if(vidas==0) emit cerrar();

    //Marcadores.
    texto="Puntos: ";
    texto+=QString::number(puntos);
    puntosLabel->setText(texto);
    texto="Vidas: ";
    texto+=QString::number(vidas);
    vidasLabel->setText(texto);
    texto="Nivel: ";
    texto+=QString::number(SI::nivel);
    nivelLabel->setText(texto);

    view->viewport()->update();
}

void Sjuego::pausar()
{
    if(timerRefresh->isActive()) timerRefresh->stop();
    else timerRefresh->start();
}

void Sjuego::definirStylesSheets()
{
    QString labelStyle;

    view->setStyleSheet("background-image: url(Fondo2.png); \
                          background-position: center; \
                        ");

    labelStyle="background-color: rgb(208, 114, 2); \
                color: rgb(0, 0, 0)";
    puntosLabel->setStyleSheet(labelStyle);
    vidasLabel->setStyleSheet(labelStyle);
    nivelLabel->setStyleSheet(labelStyle);
}

void Sjuego::choqueAlienNave()
{
    int i, j;

    for(i=0; i<5; i++)
        for(j=0; j<11; j++)
        {
            if(escuadron.alien(i, j)->isVisible() && !escuadron.alien(i, j)->explosion())
            {
                if(nave->x()+nave->anchura() < escuadron.alien(i, j)->x() || escuadron.alien(i, j)->x()+escuadron.alien(i, j)->anchura() < nave->x()){}
                else
                {
                    if(nave->y()+nave->altura() < escuadron.alien(i, j)->y() || escuadron.alien(i, j)->y()+escuadron.alien(i, j)->altura() < nave->y()){}
                    else
                    {
                        escuadron.alien(i, j)->setVisible(false);
                        nave->posIni();
                        vidas--;
                        puntos+=10;
                        escuadron.ajustarMovHorizontal(j);
                        return;
                    }
                }
            }
        }

    return;
}

void Sjuego::choqueAlienBala()
{
    int i, j;

    if(balas->isVisible())
    {
        for(i=0; i<5; i++)
            for(j=0; j<11; j++)
            {
                if(escuadron.alien(i, j)->isVisible() && !escuadron.alien(i, j)->explosion()) //La segunda condición evita que se destruya dos veces el mismo alien.
                { //Mientras dura la explosión isVisible() vale true.
                    if(balas->x()+balas->anchura() < escuadron.alien(i, j)->x() || escuadron.alien(i, j)->x()+escuadron.alien(i, j)->anchura() < balas->x()){}
                    else
                    {
                        if(balas->y()+balas->altura() < escuadron.alien(i, j)->y() || escuadron.alien(i, j)->y()+escuadron.alien(i, j)->altura() < balas->y()){}
                        else
                        {
                            escuadron.alien(i, j)->setVisible(false);
                            balas->setVisible(false);
                            puntos+=10;
                            escuadron.ajustarMovHorizontal(j);
                            return;
                        }
                    }
                }
            }
    }

    return;
}
