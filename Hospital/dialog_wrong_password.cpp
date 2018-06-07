#include "dialog_wrong_password.h"
#include "ui_dialog_wrong_password.h"

Dialog_wrong_password::Dialog_wrong_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_wrong_password)
{
    ui->setupUi(this);
}

Dialog_wrong_password::~Dialog_wrong_password()
{
    delete ui;
}
