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



#ifndef SJUEGO_H
#define SJUEGO_H

#include <Qt>
#include <QAction>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QWidget>

#include "SI.h"
#include "Sbalas.h"
#include "Sescuadron.h"
#include "Snave.h"

class Sjuego : public QWidget
{
    Q_OBJECT

    public:
        explicit Sjuego(QWidget *parent=0);
        void keyPressEvent(QKeyEvent* event);
        void keyReleaseEvent(QKeyEvent* event);

    public slots:
        void iniciar();
        void actualizar();
        void pausar();
        //void reiniciar();

    signals:
        void cerrar(); //Las señales sólo se ponen aquí. No se define nada aparte. Sólo hay que poner emit cerrar(); cuando se quiera emitir la señal.

    private:
        QGraphicsScene *escena;
        QGraphicsView *view;
        QHBoxLayout *hlayout;
        QVBoxLayout *vlayout;
        QAction *pausaAction;
        QLabel *vidasLabel, *puntosLabel, *nivelLabel;
        QTimer *timerRefresh;

        Sescuadron escuadron;
        Snave *nave;
        Sbalas *balas;

        bool key_space, key_left, key_right, key_up, key_down;
        int puntos, vidas;

        void definirStylesSheets();
        void choqueAlienNave();
        void choqueAlienBala();
};

#endif // SJUEGO_H
