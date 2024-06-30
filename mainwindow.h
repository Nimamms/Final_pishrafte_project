#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

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
    void on_PB_sign_up_clicked();

    void on_dont_have_account_stateChanged(int arg1);

    void on_PB_login_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
