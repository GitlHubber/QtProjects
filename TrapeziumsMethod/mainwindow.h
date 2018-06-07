#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtScript/QScriptEngine>
#include <QString>

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
    void on_calc_clicked();

    void on_cosX_clicked();

    void on_sinX_clicked();

    void on_tgX_clicked();

private:
    Ui::MainWindow *ui;
    QScriptEngine* m_engine;
    QScriptValue userFunction;
    QScriptValue integralFunc;
    QString Func = "( \
                   function integralpram(a, b, n, func){ \
                var h = (b-a)*1.0/n; \
                var s = func(a)+func(b); \
                for (var i = 1; i < n; i++) \
                    s += 2.0*(1.0*func(a+i*h)); \
                return (h/2.0)*s; \
            })";

};

#endif
