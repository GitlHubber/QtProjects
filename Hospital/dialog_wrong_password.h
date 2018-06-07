#ifndef DIALOG_WRONG_PASSWORD_H
#define DIALOG_WRONG_PASSWORD_H

#include <QDialog>

namespace Ui {
class Dialog_wrong_password;
}

class Dialog_wrong_password : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_wrong_password(QWidget *parent = 0);
    ~Dialog_wrong_password();

private:
    Ui::Dialog_wrong_password *ui;
};

#endif // DIALOG_WRONG_PASSWORD_H
