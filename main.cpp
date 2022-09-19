#include "mainwindow.h"
#include <QApplication>
#include <QFrame>
#include <QtGui>
#include <cstdlib>
#include <time.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <unistd.h>

int generate_random(int min, int max)
{
    return rand()%(max + 1 - min) + min;
}

QString int_to_Qstring(int num)
{
    return QString::number(num);
}

void number_generator(int num, int* arry)
{

    for(int i = 0; i < 3; i++)
    {
        int random = generate_random(num-10, num+10);
        if(random == num)
        {
            while(random == num)
            {
                random = generate_random(num-10, num+10);
            }
        }
        *arry = random;
        arry += 1;
    }
}

QString equation_generator(int* arry, int* ans)
{
    std::unordered_map<int, std::string> dict;
    int num, num1, num2;
    std::string a, b;
    num1 = rand() % 50 + 10;
    num2 = rand() % 50 + 1;
    num = generate_random(1, 3);
    a = std::to_string(num1);
    b = std::to_string(num2);
    dict.insert(make_pair(1, a + " + " + b + " = "));
    dict.insert(make_pair(2, a + " - " + b + " = "));
    dict.insert(make_pair(3, a + " * " + b + " = "));
    switch (num)
    {
        case 1:
            *ans =  num1 + num2;
            break;
        case 2:
            *ans =  num1 - num2;
            break;
        case 3:
            *ans =  num1 * num2;
            break;
    }
    number_generator(*ans, arry);
    return QString::fromStdString(dict[num]);
}

int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    MainWindow w;


//    w.setAutoFillBackground(true);
//    QPalette palette;
//    QPixmap pixmap;
//    pixmap.load("qrc/images/bgpic.jpg");
//    palette.setBrush(QPalette::Window, QBrush(pixmap));
//    w.setPalette(palette);
    w.show();
    return a.exec();
}
