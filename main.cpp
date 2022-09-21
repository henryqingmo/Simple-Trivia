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

/* This file is responsible for generating the equations and answers
 * It defines the functions which is then called in the game.cpp file through its header file.
*/


int generate_random(int min, int max)   //srand logic for generating in a range
{
    return rand()%(max + 1 - min) + min;
}

QString int_to_Qstring(int num)    //convert int to Qstring requried by setText function
{
    return QString::number(num);
}

void number_generator(int num, int* arry)   //generate three numbers based on a number and is not equal to that number
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
        *arry = random; //The three answers are stored in this array initiallised in game.cpp
        arry += 1; //adding values to a pointer is a way of looping through an array for its sequential nature in memory.
    }
}

QString equation_generator(int* arry, int* ans)  //using hashmap to store operations as numbers 1 to 3 and randomly selects an operation
{
    std::unordered_map<int, std::string> dict;
    int operation, num1, num2;
    std::string a, b;
    num1 = rand() % 50 + 10;   //The two numbers for the equation generates here
    num2 = rand() % 50 + 1;
    operation = generate_random(1, 3);
    a = std::to_string(num1);
    b = std::to_string(num2);
    dict.insert(make_pair(1, a + " + " + b + " = "));
    dict.insert(make_pair(2, a + " - " + b + " = "));
    dict.insert(make_pair(3, a + " * " + b + " = "));
    switch (operation)
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
    return QString::fromStdString(dict[operation]); //called in game.cpp line 23 for displaying the equaiotn
}

int main(int argc, char *argv[]) //initialise the mainwindow
{ 
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
