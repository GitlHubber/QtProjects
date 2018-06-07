#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "dialog_for_doctor.h"
#include "dialog_for_patient.h"
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class QSqlTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Patient_clicked();
    void keyPressEvent(QKeyEvent* event);
    void on_Doctor_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel* mModel;
    QSqlDatabase mDatabase;
    Dialog_for_doctor* window_doctor;
    Dialog_for_patient* window_pacient;
};

#endif // MAINWINDOW_H
