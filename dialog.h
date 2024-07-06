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
    explicit Dialog(const QString & key_username ,QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_PB_continue_clicked();

private:
    Ui::Dialog *ui;
    QString Key_Username ;

};

#endif // DIALOG_H
