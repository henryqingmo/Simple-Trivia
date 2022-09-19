#include "game.h"
#include "ui_game.h"
#include "main.h"
#include "result.h"
#include <string>
#include <vector>

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
        break;
    case 2:
        ui->buttonB->setText(int_to_Qstring(ans));
        vect.erase(vect.begin()+1);
        break;
    case 3:
        ui->buttonC->setText(int_to_Qstring(ans));
        vect.erase(vect.begin()+2);
        break;
    case 4:
        ui->buttonD->setText(int_to_Qstring(ans));
        vect.erase(vect.end());
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


void Game::on_buttonA_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
}


void Game::on_buttonB_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
}


void Game::on_buttonC_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
}


void Game::on_buttonD_clicked()
{
    Result result;
    result.setModal(true);
    result.exec();
}

