#include "game.h"
#include "ui_game.h"
#include "main.h"
#include "result.h"
#include <string>
#include <vector>
#include <QGuiApplication>

int check;
bool isAnswer = false;

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    int ans;
    int* ptn_ans = &ans;
    int arry[3];
    std::vector<QPushButton *> vect = {ui->buttonA, ui->buttonB, ui->buttonC, ui->buttonD};
    srand(time(NULL));
    equation_generator(arry, ptn_ans);
    ui->textBrowser->setText(equation_generator(arry, ptn_ans));
    int num = generate_random(1, 4);
    switch (num) {
    case 1:
        ui->buttonA->setText(int_to_Qstring(ans));
        vect.erase(vect.begin());
        check = 1;
        break;
    case 2:
        ui->buttonC->setText(int_to_Qstring(ans));
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
        vect[i]->setText(int_to_Qstring(arry[i]));
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


void Game::on_buttonA_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
    if(check == 1)
    {
        isAnswer = true;
    }
}


void Game::on_buttonB_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
    if(check == 2)
    {
        isAnswer = true;
    }
}


void Game::on_buttonC_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
    if(check == 3)
    {
        isAnswer = true;
    }
}


void Game::on_buttonD_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
    if(check == 4)
    {
        isAnswer = true;
    }
}
