#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QList>
#include <QVBoxLayout>
#include "conjugatedradient.h"
#include <QRegExpValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void changeValue(int r);
    void on_calc_clicked();


private:
    Ui::MainWindow *ui;
    ConjugateDradient* conjugateGradient;
    QRegExpValidator* validator;
};


#endif
