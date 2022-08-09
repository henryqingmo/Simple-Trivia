#include "credit_dialog.h"
#include "ui_credit_dialog.h"

credit_dialog::credit_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credit_dialog)
{
    ui->setupUi(this);
}

credit_dialog::~credit_dialog()
{
    delete ui;
}
