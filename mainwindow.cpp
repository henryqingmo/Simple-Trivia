#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "credit_dialog.h"
#include "game.h"
#include <QMediaPlayer>
#include <QPixmap>
#include <QPalette>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->muteCheckbox->setCheckState(Qt::Checked);
    QMediaPlayer *music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked() //Creates the game widget
{
   Game game;
   game.setModal(true);
   game.exec();
}


void MainWindow::on_creditButton_clicked() //Creates the credit widget
{
   credit_dialog Dialog;
   Dialog.setModal(true);
   Dialog.exec();

}



void MainWindow::on_muteCheckbox_stateChanged(int arg1)
{
    QMediaPlayer *music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    if(ui->muteCheckbox->isChecked() && arg1)
    {
        music->play();
    }
    else
    {
        music->pause();  //This is not working for some reason
    }

}



