#include "result.h"
#include "ui_result.h"
#include "game.h"
#include <QGuiApplication>

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    if(isAnswer == true) //Checking the value of isAnswer keywords defined in game.cpp
    {
        ui->textBrowser->setText("correct");
    }
    else
    {
        ui->textBrowser->setText("incorrect");
    }
    isAnswer = false;
}

Result::~Result()
{
    delete ui;
}

void Result::on_buttonBox_accepted() //Generating new widget.
{
    Game game;
    game.setModal(true);
    game.exec();

}


