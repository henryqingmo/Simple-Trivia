#ifndef GAME_H
#define GAME_H

#include <QDialog>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

signals:
    void sendAnswer(bool check, QString answer);

private slots:
    void on_buttonA_clicked(int check);

    void on_buttonA_clicked();

    void on_buttonB_clicked();

    void on_buttonC_clicked();

    void on_buttonD_clicked();

private:
    Ui::Game *ui;
};

#endif // GAME_H
