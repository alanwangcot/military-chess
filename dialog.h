#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void initial();

signals:
//    void IPInputted();
    void connectButtonClicked(QString ip);
private slots:
    void on_ConnectButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::Dialog *ui;
    QString input;
};

#endif // DIALOG_H
