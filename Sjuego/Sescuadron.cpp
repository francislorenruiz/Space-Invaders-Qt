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



#include "Sescuadron.h"

Sescuadron::Sescuadron(QObject *parent): QObject(parent)
{
    int i, j;

    x=10;
    y=10;

    for(i=0; i<5; i++)
        for(j=0; j<11; j++)
        {
            escuadron[i][j]=new Salien();
            escuadron[i][j]->cargarImagen(i);
            escuadron[i][j]->setPos(x +(escuadron[i][j]->anchura()+20)*j, y +(escuadron[i][j]->altura()+20)*i);
        }

    timer=new QTimer();
    timer->setSingleShot(true);
    timer->setInterval(escuadron[0][0]->duracionExplosion()+10);
    connect(timer, SIGNAL(timeout()), this, SLOT(siguienteNivel()));

    for(i=0; i<11; i++) aliensColumna[i]=5;
    velx=1;
    vely=0.01;
    minx=0;
    maxx=SI::ancho-665;
    primeraColum=0;
    ultimaColum=10;
    b_destruido=false;
}

void Sescuadron::cargar(QGraphicsScene *escena)
{
    int i, j;

    for(i=0; i<5; i++)
        for(j=0; j<11; j++)
            escena->addItem(escuadron[i][j]);
    return;
}

void Sescuadron::trasladar(float posx, float posy)
{
    int i, j;

    x=posx;
    y=posy;

    for(i=0; i<5; i++)
        for(j=0; j<11; j++)
            escuadron[i][j]->setPos(posx +(escuadron[i][j]->anchura()+20)*j, posy +(escuadron[i][j]->altura()+20)*i);
}

float Sescuadron::alienX(int fila, int columna)
{
    return escuadron[fila][columna]->x();
}

float Sescuadron::alienY(int fila, int columna)
{
    return escuadron[fila][columna]->y();
}

Salien* Sescuadron::alien(int fila, int columna)
{
    return escuadron[fila][columna];
}

void Sescuadron::ajustarMovHorizontal(int columna)
{
    int i;

    aliensColumna[columna]--;
    if(aliensColumna[columna]==0)
    {
        if(primeraColum==columna)
        {
            i=0;
            do{
                primeraColum++;
                minx-=escuadron[0][columna+i]->anchura()+20;
                i++;
            }while(aliensColumna[columna+i]==0);
        }

        if(ultimaColum==columna)
        {
            i=0;
            do{
                ultimaColum--;
                maxx+=escuadron[0][columna-i]->anchura()+20;
                i++;
            }while(aliensColumna[columna-i]==0);
        }
    }

    if(primeraColum >ultimaColum)
    {
        timer->start();
        b_destruido=true;
    }

    return;
}

void Sescuadron::moveBy()
{
    int i, j;

    if(x>=maxx || x<=minx) velx*=-1;

    x+=velx;
    y+=vely;

    for(i=0; i<5; i++)
        for(j=0; j<11; j++)
            escuadron[i][j]->moveBy(velx, vely);
}

bool Sescuadron::destruido()
{
    return b_destruido;
}

void Sescuadron::siguienteNivel()
{
    int i, j;

    x=10;
    y=10;

    for(i=0; i<5; i++)
        for(j=0; j<11; j++)
        {
            escuadron[i][j]->setVisible(true);
            escuadron[i][j]->setPos(x +(escuadron[i][j]->anchura()+20)*j, y +(escuadron[i][j]->altura()+20)*i);
        }

    for(i=0; i<11; i++) aliensColumna[i]=5;
    if(velx>0) velx+=0.10;
    else velx-=0.10;
    vely+=0.01;
    minx=0;
    maxx=SI::ancho-665;
    primeraColum=0;
    ultimaColum=10;
    SI::nivel++;
    b_destruido=false;
}
