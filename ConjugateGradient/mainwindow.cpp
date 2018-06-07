#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conjugatedradient.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rank->setMaximum(9);
    ui->rank->setMinimum(2);
    ui->matrixAFrame->setLayout(new QVBoxLayout());
    ui->vecBFrame->setLayout(new QVBoxLayout());
    connect(ui->rank, SIGNAL(valueChanged(int)), this, SLOT(changeValue(int)));
    validator = new QRegExpValidator(QRegExp ("([\\d\\-][\\de. ]{1,20})"), this);
    for(int i = 0; i < 2; ++i)
    {
        QLineEdit* temp = new QLineEdit();
        temp->setValidator(validator);
        ui->matrixAFrame->layout()->addWidget(temp);
        QLineEdit* temp1 = new QLineEdit();
        temp1->setValidator(validator);
        ui->vecBFrame->layout()->addWidget(temp1);
    }
    conjugateGradient = new ConjugateDradient();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString vectorToString(std::vector<double> test)
{
    QString result;
    for(auto i = test.begin(); i != test.end(); ++i)
    {
        result = result + QString().setNum(*i);
        result.push_back(' ');
    }
    return result;
}

std::vector<double> stringToVector1(QString s)
{
    std::string str = s.toStdString();
    str.push_back(' ');
    std::string temp;
    std::vector<double> result;
    for(auto i = str.begin(); i != str.end(); ++i)
    {
        if(*i == ' ')
        {
            result.push_back(std::stod(temp));
            temp.clear();
        }
        temp.push_back(*i);
    }
    return result;
}

void MainWindow::changeValue(int r)
{
    QList<QLineEdit*> list = ui->matrixAFrame->findChildren<QLineEdit*>();
    QList<QLineEdit*> vec = ui->vecBFrame->findChildren<QLineEdit*>();
    for(auto i : list)
    {
        delete i;
    }
    for(auto i : vec)
    {
        delete i;
    }

    for(int i = 0; i < r; ++i)
    {
        QLineEdit* temp = new QLineEdit();
        temp->setValidator(validator);
        ui->matrixAFrame->layout()->addWidget(temp);
        QLineEdit* temp1 = new QLineEdit();
        temp1->setValidator(validator);
        ui->vecBFrame->layout()->addWidget(temp1);
    }
}

void MainWindow::on_calc_clicked()
{
    QList<QLineEdit*> list = ui->matrixAFrame->findChildren<QLineEdit*>();
    QList<QLineEdit*> vec = ui->vecBFrame->findChildren<QLineEdit*>();

    for(auto i = list.begin(); i != list.end(); ++i)
    {
        if((*i)->text() == "")
        {
            QMessageBox::critical(this, "Внимание!", "Есть не заполненные поля.");
            return;
        }
        conjugateGradient->A.push_back(stringToVector1((*i)->text()));
    }
    for(auto i = vec.begin(); i != vec.end(); ++i)
    {
        if((*i)->text() == "")
        {
            QMessageBox::critical(this, "Внимание!", "Есть не заполненные поля.");
            return;
        }
        QString temp = (*i)->text();
        conjugateGradient->B.push_back(std::stod(temp.toStdString()));
    }
    conjugateGradient->calc();
    ui->matrixX->setText(vectorToString(conjugateGradient->res));
}
