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


#ifndef SNAVE_H
#define SNAVE_H

#include "SI.h"
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Snave : public QGraphicsPixmapItem
{
    public:
        Snave(QGraphicsItem *parent = 0);
        void moveBy(qint8 dx, qint8 dy); //Se modifica para que la nave no se salga de la pantalla. Además las variables dx, dy sólo indican la dirección.
        void posIni(); //Mueve la nave a la posición inicial.
        void siguienteNivel();
        int anchura();
        int altura();

    private:
        int anch, alt;
        float vel;
};

#endif // SNAVE_H
