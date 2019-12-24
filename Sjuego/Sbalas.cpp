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



#include "Sbalas.h"

Sbalas::Sbalas(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    QPixmap pixmap;

    pixmap.load("Bala.png");
    setPixmap(pixmap);
    setVisible(false);
}

void Sbalas::disparar(int posx, int posy)
{
    if(!isVisible())
    {
        setPos(posx, posy);
        setVisible(true);
    }
}

void Sbalas::moveBy()
{
    if(isVisible()) QGraphicsPixmapItem::moveBy(0, -10);
    if(y()<=0) setVisible(false);
}

int Sbalas::anchura()
{
    return 2;
}

int Sbalas::altura()
{
    return 10;
}
