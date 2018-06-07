#ifndef PATIENT_CARD_H
#define PATIENT_CARD_H



namespace Ui {
class Patient_card;
}

class Patient_card : public QDialog
{
    Q_OBJECT

public:
    explicit Patient_card(QWidget *parent = 0);
    ~Patient_card();

public slots:
    void start(QString id);
private slots:
    void startDisease(QString id);

private:

};

#endif // PATIENT_CARD_H
