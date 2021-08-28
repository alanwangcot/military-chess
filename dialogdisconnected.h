#ifndef DIALOGDISCONNECTED_H
#define DIALOGDISCONNECTED_H

#include <QDialog>

namespace Ui {
class DialogDisconnected;
}

class DialogDisconnected : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDisconnected(QWidget *parent = nullptr);
    ~DialogDisconnected();

private:
    Ui::DialogDisconnected *ui;
};

#endif // DIALOGDISCONNECTED_H
