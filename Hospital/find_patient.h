#ifndef FIND_PATIENT_H
#define FIND_PATIENT_H

#include <QDialog>
#include "pacient_info_editor.h"
#include <QSqlQuery>
#include <QDataWidgetMapper>
#include <QStandardItemModel>

namespace Ui {
class find_patient;
}

class find_patient : public QDialog
{
    Q_OBJECT

public:
    explicit find_patient(QWidget *parent = 0);
    ~find_patient();


public slots:
    void on_find_clicked();

private slots:
private:
    Ui::find_patient *ui;
    pacient_info_editor* editor;
    QSqlQuery query;
    QString Name;
    QString Surname;
    int Age;
    int disease;
    QString id;
};

#endif // FIND_PATIENT_H
