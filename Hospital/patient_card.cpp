
#include <QSqlQuery>
#include <QSqlTableModel>

Patient_card::Patient_card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Patient_card)
{
    ui->setupUi(this);
}

Patient_card::~Patient_card()
{
    delete ui;
}






