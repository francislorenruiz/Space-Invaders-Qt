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


#include "Sjuego/SI.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QApplication>
#include <QSound>

int main(int argc, char *argv[])
{
    int x, y;
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget *desktop = QApplication::desktop(); //Esto es para centrar la ventana en la pantalla.

    x = desktop->width();
    y = desktop->height();
    x=(x-SI::ancho)/2;
    y=(y-SI::alto+20)/2;
    w.move( x, y );
    w.show();

    return a.exec();
}
