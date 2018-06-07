#include "dialog_for_doctor.h"
#include "ui_dialog_for_doctor.h"
#include <dialog_for_doctor2.h>
#include <QMessageBox>

Dialog_for_doctor::Dialog_for_doctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_for_doctor)
{
    ui->setupUi(this);
}

Dialog_for_doctor::~Dialog_for_doctor()
{
    delete ui;
}

void Dialog_for_doctor::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "admin")
    {
        Dialog_for_doctor2 *showcards;
        showcards = new Dialog_for_doctor2();
        showcards->show();
        this->hide();
    }
    else if(ui->lineEdit->text() == nullptr)
    {
        QMessageBox::about(this, "About password", "Вы не ввели пароль, а следовало бы");
    }
    else
    {
        QMessageBox::critical(this, "Wrong password", "Пароль введен неправильно.");
    }
}

