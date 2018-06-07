#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_engine = new QScriptEngine();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calc_clicked()
{
    int from = ui->lineEditFrom->text().toInt();
    int to = ui->lineEditTo->text().toInt();
    if(from > to)
        QMessageBox::about(this, "Attention", "Высший предел меньше низшего.");

    QString f = "(function func(x){return ";
    f = f + ui->func->text();
    f = f + " ;})";
    userFunction = m_engine->evaluate(f);
    QScriptValue a = m_engine->evaluate(ui->lineEditFrom->text());
    QScriptValue b = m_engine->evaluate(ui->lineEditTo->text());
    QScriptValue n = m_engine->evaluate(ui->splitting->text());
    integralFunc = m_engine->evaluate(Func);

    QScriptValueList args;
    args << a.toNumber() << b.toNumber() << n.toNumber() << userFunction;

    QScriptValue result = integralFunc.call(QScriptValue(), args);
    ui->result->setText(result.toString());
}

void MainWindow::on_cosX_clicked()
{
    ui->func->setText("Math.cos(x)");
}

void MainWindow::on_sinX_clicked()
{
    ui->func->setText("Math.sin(x)");
}

void MainWindow::on_tgX_clicked()
{
    ui->func->setText("Math.tan(x)");
}
