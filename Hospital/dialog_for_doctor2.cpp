#include "dialog_for_doctor2.h"
#include "ui_dialog_for_doctor2.h"

Dialog_for_doctor2::Dialog_for_doctor2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_for_doctor2)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("patient");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(4);
}

Dialog_for_doctor2::~Dialog_for_doctor2()
{
    delete ui;
}

void Dialog_for_doctor2::on_sort_clicked()
{
    type = ui->comboBox->currentText();
    if(type == "По алфавиту А-Я")
    {
        model->setTable("patient");
        model->setSort(1, Qt::AscendingOrder);
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->hideColumn(0);
    }
    else if(type == "По алфавиту Я-А")
    {
        model->setTable("patient");
        model->setSort(1, Qt::DescendingOrder);
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->hideColumn(0);
    }
    else if(type == "По возрасту 0-9")
    {
        model->setTable("patient");
        model->setSort(3, Qt::AscendingOrder);
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->hideColumn(0);
    }
    else
    {
        model->setTable("patient");
        model->setSort(3, Qt::DescendingOrder);
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->hideColumn(0);
    }
}

void Dialog_for_doctor2::on_find_patient_clicked()
{
    patient = new find_patient(this);
    patient->show();
}
