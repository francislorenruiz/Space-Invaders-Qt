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


#ifndef SALIEN_H
#define SALIEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Salien :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        explicit Salien(QObject *parent = 0, QGraphicsItem *parent2 = 0);
        void cargarImagen(int fila); //Carga la imagen del alien dependiendo de la fila en la que esté.
        void setVisible(bool visible);
        int duracionExplosion();
        int anchura();
        int altura();
        bool explosion();

    private slots:
        void eliminarExplosion();

    private:
        QTimer *timer;
        int int_fila, anch, alt, int_duraExpl;
        bool bool_expl;
};

#endif // SALIEN_H
