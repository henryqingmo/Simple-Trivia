#include "mainwindow.h"
#include <QApplication>
#include <QFrame>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); 
    MainWindow w;
    w.setStyleSheet("background-image: url(:/qrc/images/bgpic.jpg);");





//    w.setAutoFillBackground(true);
//    QPalette palette;
//    QPixmap pixmap;
//    pixmap.load("qrc/images/bgpic.jpg");
//    palette.setBrush(QPalette::Window, QBrush(pixmap));
//    w.setPalette(palette);
    w.show();
    return a.exec();
}
