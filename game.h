#ifndef GAME_H
#define GAME_H

#include <QDialog>

extern bool isAnswer; //value of isAnswer is shared to result.cpp through here.

void update_game();

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private slots:

    void on_buttonA_clicked();

    void on_buttonB_clicked();

    void on_buttonC_clicked();

    void on_buttonD_clicked();

    void on_exitButton_clicked();

private:
    Ui::Game *ui;
};

#endif // GAME_H
