#ifndef DIALOG_FOR_PATIENT_H
#define DIALOG_FOR_PATIENT_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class Dialog_for_patient;
}

class Dialog_for_patient : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_for_patient(QWidget *parent = 0);
    ~Dialog_for_patient();

public slots:
    void start(QString id);
    void disease_edit(QString id);

private slots:
    void on_find_clicked();

private:
    Ui::Dialog_for_patient *ui;
    QSqlQuery query;
    QString Name;
    QString Surname;
    int age;
    int disease1;

    QString disease;
    QString date_of_disease;
    QSqlTableModel* model;
    QSqlDatabase mDatabase;
};

#endif // DIALOG_FOR_PATIENT_H
