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


#include "Snave.h"

Snave::Snave(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    QPixmap pixmap;

    pixmap.load("Nave.png");
    setPixmap(pixmap);
    vel=5;
    anch=45; //Si se cambia, ver posIni();
    alt=58;

    setPos(SI::ancho/2-20, SI::alto-60); //El 20 no se sustituye por anch/2, porque entonces la nave se sale un poco de los límites de su movimiento.
}

void Snave::moveBy(qint8 dx, qint8 dy)
{
    if(x()<=0 && dx<0) dx=0;
    if(x()>=SI::ancho-vel-anch && dx>0) dx=0; //Se le resta la velocidad (se mueve esos píxeles cada vez) para que la nave se quede dentro de la ventana.
    if(y()<=0 && dy) dy=0;//if(y()<=SI::alto*2/3 && dy<0) dy=0;
    if(y()>=SI::alto-vel-alt && dy>0) dy=0;

    QGraphicsPixmapItem::moveBy(dx*vel, dy*vel);
}

void Snave::posIni()
{
    setPos(SI::ancho/2-20, SI::alto-60);
}

void Snave::siguienteNivel()
{
    vel+=0.05;
}

int Snave::anchura()
{
    return anch;
}

int Snave::altura()
{
    return alt;
}
