#ifndef PACIENT_INFO_EDITOR_H
#define PACIENT_INFO_EDITOR_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class pacient_info_editor;
}

class pacient_info_editor : public QDialog
{
    Q_OBJECT

public:
    explicit pacient_info_editor(QWidget *parent = 0);
    ~pacient_info_editor();

public slots:
    void start(QString id);
    void disease_edit(QString id);

private slots:
    void on_addButton_clicked();

    void on_updateButton_clicked();

    void on_pushButton_clicked();

    void on_delButton_clicked();

private:
    Ui::pacient_info_editor *ui;
    QSqlQuery query;
    QString Name;
    QString Surname;
    int Age;
    int disease;
    QSqlTableModel* model;
    QString _id;
};

#endif // PACIENT_INFO_EDITOR_H
