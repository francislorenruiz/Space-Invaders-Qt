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


#include "Salien.h"

Salien::Salien(QObject *parent, QGraphicsItem *parent2) :
    QObject(parent), QGraphicsPixmapItem(parent2)
{
    int_duraExpl=100;
    bool_expl=false;

    timer=new QTimer();
    timer->setSingleShot(true);
    timer->setInterval(int_duraExpl);

    connect(timer, SIGNAL(timeout()), this, SLOT(eliminarExplosion()));
}

void Salien::cargarImagen(int fila)
{
    QPixmap pixmap;

    int_fila=fila;

    if(fila==0)
    {
        pixmap.load("Alien1.png");
        setPixmap(pixmap);

        anch=42;
        alt=30;
    }

    if(fila==1)
    {
        pixmap.load("Alien2.png");
        setPixmap(pixmap);

        anch=42;
        alt=30;
    }

    if(fila==2)
    {
        pixmap.load("Alien1.png");
        setPixmap(pixmap);

        anch=42;
        alt=30;
    }

    if(fila==3)
    {
        pixmap.load("Alien2.png");
        setPixmap(pixmap);

        anch=42;
        alt=30;
    }

    if(fila==4)
    {
        pixmap.load("Alien1.png");
        setPixmap(pixmap);

        anch=42;
        alt=30;
    }
}

void Salien::setVisible(bool visible)
{
    QPixmap pixmap;

    if(!visible)
    {
        pixmap.load("Explosion.png");
        setPixmap(pixmap);
        bool_expl=true;
        timer->start();
    }
    else QGraphicsPixmapItem::setVisible(true);
}

int Salien::duracionExplosion()
{
    return int_duraExpl;
}

int Salien::anchura()
{
    return anch;
}

int Salien::altura()
{
    return alt;
}

bool Salien::explosion()
{
    return bool_expl;
}

void Salien::eliminarExplosion()
{
    cargarImagen(int_fila);
    bool_expl=false;

    QGraphicsPixmapItem::setVisible(false);
}
