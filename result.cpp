#include "result.h"
#include "ui_result.h"
#include "game.h"
#include <QGuiApplication>

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    if(isAnswer == true)
    {
        ui->textBrowser->setText("correct");
    }
    else
    {
        ui->textBrowser->setText("incorrect");
    }
}

Result::~Result()
{
    delete ui;
}

void Result::on_buttonBox_accepted()
{
    update_game();
    qApp->processEvents();
}


