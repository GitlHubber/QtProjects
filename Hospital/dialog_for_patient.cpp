#include "dialog_for_patient.h"
#include "ui_dialog_for_patient.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>

Dialog_for_patient::Dialog_for_patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_for_patient)
{
    ui->setupUi(this);
}

Dialog_for_patient::~Dialog_for_patient()
{
    delete ui;
}

void Dialog_for_patient::disease_edit(QString id)
{
    model = new QSqlTableModel(this);
    model->setTable("diseas_history");
    model->setFilter("id_card = "+id+"");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
}

void Dialog_for_patient::start(QString id)
{
    query.exec("SELECT * FROM patient WHERE id = "+id+"");

    while(query.next())
    {
        Name = query.value(1).toString();
        Surname = query.value(2).toString();
        age = query.value(3).toInt();
        disease1 = query.value(4).toInt();
    }

    ui->Name_1->setText(Name);
    ui->Surname_1->setText(Surname);
    ui->Age_1->setText(QString::number(age));
    disease_edit(id);
}

void Dialog_for_patient::on_find_clicked()
{
    if (ui->idcard->text() != "")
    {
        start(ui->idcard->text());
    }
    else if((ui->Surname->text() == nullptr) && (ui->Name->text() == nullptr))
    {
        QMessageBox::critical(this, "Error", "Неправильно введены данные!\nВведите номер карточки или Имя и Фамилию!");
    }
    else
    {
        if(ui->Name->text() == nullptr && ui->Surname->text() == nullptr)
        {
            QMessageBox::critical(this, "Error", "Вы ничего не ввели, введите хоть что-то наконец.");
        }
        else if(ui->Name->text() == nullptr && ui->Surname->text() != nullptr)
        {
            QMessageBox::about(this, "Enter you name", "Вы не ввели свое имя.");
        }
        else if(ui->Surname->text() == nullptr && ui->Name->text() != nullptr)
        {
            QMessageBox::about(this, "Enter you surname", "Вы не ввели свою фамилию.");
        }
        else
        {
            QSqlQuery query;
            QString id;
            query.exec("SELECT id FROM patient WHERE name = '"+ui->Name->text()+"' AND surname = '"+ui->Surname->text()+"'");
            while(query.next())
            {
                id = query.value(0).toString();
            }

            if(id != "")
            {
                start(id);
            }
            else
            {
                QMessageBox::about(this, "Error", "Card not found.");
                qDebug() << ui->Name->text();
            }
        }
    }
}
