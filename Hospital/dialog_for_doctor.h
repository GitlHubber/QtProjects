#ifndef DIALOG_FOR_DOCTOR_H
#define DIALOG_FOR_DOCTOR_H

#include <QDialog>

namespace Ui {
class Dialog_for_doctor;
}

class Dialog_for_doctor : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_for_doctor(QWidget *parent = 0);
    ~Dialog_for_doctor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_for_doctor *ui;
};

#endif // DIALOG_FOR_DOCTOR_H
