#include "find_patient.h"
#include "ui_find_patient.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

find_patient::find_patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::find_patient)
{
    ui->setupUi(this);
}

find_patient::~find_patient()
{
    delete ui;
}

void find_patient::on_find_clicked()
{
    if(ui->Name1->text() == nullptr && ui->Surname1->text() == nullptr)
    {
        QMessageBox::critical(this, "Error", "Вы ничего не ввели, введите хоть что-то наконец.");
    }
    else if(ui->Name1->text() == nullptr && ui->Surname1->text() != nullptr)
    {
        QMessageBox::about(this, "Enter you name", "Вы не ввели свое имя.");
    }
    else if(ui->Surname1->text() == nullptr && ui->Name1->text() != nullptr)
    {
        QMessageBox::about(this, "Enter you surname", "Вы не ввели свою фамилию.");
    }
    else
    {
        QSqlQuery query;

        query.exec("SELECT id FROM patient WHERE name = '"+ui->Name1->text()+"' AND surname = '"+ui->Surname1->text()+"'");
        while(query.next())
        {
            id = query.value(0).toString();
        }

        if(id != "")
        {
            editor = new pacient_info_editor(this);
            editor->show();
            editor->start(id);
        }
        else
        {
            QMessageBox::about(this, "Error", "Card not found.");
            qDebug() << ui->Name1->text();
        }
    }
}
