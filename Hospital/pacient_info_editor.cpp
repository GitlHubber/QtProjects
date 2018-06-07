#include "pacient_info_editor.h"
#include "ui_pacient_info_editor.h"
#include <QSqlQuery>
#include <QSqlTableModel>

pacient_info_editor::pacient_info_editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pacient_info_editor)
{
    ui->setupUi(this);
}

void pacient_info_editor::disease_edit(QString id)
{
    _id = id;
    model = new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("diseas_history");
    model->setFilter("id_card = "+id+"");
    model->select();
    ui->Diseases->setModel(model);
    //ui->Diseases->hideColumn(0);
}

void pacient_info_editor::start(QString id)
{
    query.exec("SELECT * FROM patient WHERE id = "+id+"");

    while(query.next())
    {
        Name = query.value(1).toString();
        Surname = query.value(2).toString();
        Age = query.value(3).toInt();
        disease = query.value(4).toInt();
    }
    ui->Name1->setText(Name);
    ui->Surname1->setText(Surname);
    ui->Age1->setText(QString::number(Age));
    disease_edit(id);
}

pacient_info_editor::~pacient_info_editor()
{
    delete ui;
}

void pacient_info_editor::on_addButton_clicked()
{
    model->insertRow(model->rowCount());
}

void pacient_info_editor::on_updateButton_clicked()
{
    model->submitAll();
}

void pacient_info_editor::on_pushButton_clicked()
{
    model->revertAll();
}

void pacient_info_editor::on_delButton_clicked()
{
    int selectRow = ui->Diseases->currentIndex().row();
    if(selectRow >= 0)
    {
        model->removeRow(selectRow);
    }
}
