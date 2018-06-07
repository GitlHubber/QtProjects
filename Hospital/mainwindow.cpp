#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("Больница №7");

    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setDatabaseName("Data/hospital.db");
    mDatabase.open();
    if(!mDatabase.open())
    {
        QMessageBox::critical(this, "Error open",
        mDatabase.lastError().text()); return;
    }
    mModel = new QSqlTableModel(this);
    mModel->setTable("patient");
    mModel->select();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Patient_clicked()
{
    window_pacient = new Dialog_for_patient(this);
    window_pacient->show();
}

void MainWindow::on_Doctor_clicked()
{
    window_doctor = new Dialog_for_doctor(this);
    window_doctor->show();
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case Qt::Key_F1: QDesktopServices::openUrl(QUrl::fromLocalFile("Data/Help.chm"));
    }
}

