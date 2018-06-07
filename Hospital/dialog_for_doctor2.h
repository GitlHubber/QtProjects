#ifndef DIALOG_FOR_DOCTOR2_H
#define DIALOG_FOR_DOCTOR2_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "find_patient.h"

namespace Ui {
class Dialog_for_doctor2;
}

class Dialog_for_doctor2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_for_doctor2(QWidget *parent = 0);
    ~Dialog_for_doctor2();

private slots:
    void on_sort_clicked();
    void on_find_patient_clicked();

private:
    Ui::Dialog_for_doctor2 *ui;
    QString type;
    QSqlQuery query;
    QSqlTableModel* model;
    find_patient* patient;
};

#endif // DIALOG_FOR_DOCTOR2_H
