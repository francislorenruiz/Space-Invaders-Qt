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


#ifndef SESCUADRON_H
#define SESCUADRON_H

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include "SI.h"
#include "Salien.h"

class Sescuadron: public QObject
{
    Q_OBJECT

    public:
        Sescuadron(QObject *parent = 0);
        void cargar(QGraphicsScene *escena);
        void trasladar(float posx, float posy);
        float alienX(int fila, int columna);
        float alienY(int fila, int columna);
        Salien* alien(int fila, int columna);
        void ajustarMovHorizontal(int columna); //Ajusta el movimiento horizontal al ser eliminada una columna entera. Recibe la columna a la que pertenece el último alien eliminado.
        void moveBy();
        bool destruido();

    public slots:
        void siguienteNivel();

    private:
        Salien *escuadron[5][11];
        QTimer *timer;
        float x, y, velx, vely;
        int aliensColumna[11], minx, maxx, primeraColum, ultimaColum;
        bool b_destruido;
};

#endif // SESCUADRON_H
