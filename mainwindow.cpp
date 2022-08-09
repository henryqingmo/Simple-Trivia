#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "credit_dialog.h"
#include <QMediaPlayer>
#include <QPixmap>
#include <QPalette>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->muteCheckbox->setCheckState(Qt::Checked);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_creditButton_clicked()
{
   credit_dialog Dialog;
   Dialog.setModal(true);
   Dialog.exec();

}




void MainWindow::on_muteCheckbox_stateChanged(int arg1)
{
    QMediaPlayer *music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    if(ui->muteCheckbox->isChecked() && music->state() == QMediaPlayer::StoppedState)
    {
       music->play();
    }
    else
    {
        music->stop();
    }
}

