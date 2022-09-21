#include "game.h"
#include "ui_game.h"
#include "main.h"
#include "result.h"
#include <string>
#include <vector>
#include <QGuiApplication>

int check, score;
bool isAnswer = false;


Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    int ans;                      //initiallise the correct answer and the array to store the wrong answers
    int* ptn_ans = &ans;
    int arry[3];
    std::vector<QPushButton *> vect = {ui->buttonA, ui->buttonB, ui->buttonC, ui->buttonD};  //button objects are put into an dynamic array
    srand(time(NULL));
    ui->textBrowser->setText(equation_generator(arry, ptn_ans)); //calling function in main.cpp to display equation
    ui->lcdNumber->display(score);  //setting the value for score


    /*
    *  A random number is selected from 1 to 4 which corresponds to button A to D and the one selected displays the correct answer
    *  and is removed from the wrong answer array. Check is set to the corresponding number inwhich the button bonds to the correct answer.
    */


    int num = generate_random(1, 4);
    switch (num) {
    case 1:
        ui->buttonA->setText(int_to_Qstring(ans));
        vect.erase(vect.begin());
        check = 1;
        break;
    case 2:
        ui->buttonB->setText(int_to_Qstring(ans));
        vect.erase(vect.begin()+1);
        check = 2;
        break;
    case 3:
        ui->buttonC->setText(int_to_Qstring(ans));
        vect.erase(vect.begin()+2);
        check = 3;
        break;
    case 4:
        ui->buttonD->setText(int_to_Qstring(ans));
        vect.erase(vect.end());
        check = 4;
        break;
    }

    for(int i = 0; i < 3; i++)
    {
        vect[i]->setText(int_to_Qstring(arry[i]));  //Through this for loop, buttons are assigned with their wrong answers generated in main.cpp
    }

}



Game::~Game()
{

    delete ui;
}


void update_game()
{
    qApp->processEvents();
}

/* On click events, result widget is created and each button's corresponding value is checked against the corresponding number where the the button bonds
 * to the correct answer. And if the button is correct,  isAnswer is set to true which determines the message to user in the result.cpp file
 * Via extern keywords, global variables can be shared through multiple cpp files. Extern keywords can be found in the header file.
*/

void Game::on_buttonA_clicked()
{
    if(check == 1)
    {
        isAnswer = true;
        score += 1;
    }
    Result result;
    result.setModal(true);
    result.exec();
}


void Game::on_buttonB_clicked()
{
    if(check == 2)
    {
        isAnswer = true;
        score += 1;
    }
    Result result;
    result.setModal(true);
    result.exec(); 
}


void Game::on_buttonC_clicked()
{
    if(check == 3)
    {
        isAnswer = true;
        score += 1;
    }
    Result result;
    result.setModal(true);
    result.exec();
}


void Game::on_buttonD_clicked()
{
    if(check == 4)
    {
        isAnswer = true;
        score += 1;
    }
    Result result;
    result.setModal(true);
    result.exec();
}

void Game::on_exitButton_clicked()
{
   exit(EXIT_FAILURE);
}

