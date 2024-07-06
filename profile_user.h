#ifndef PROFILE_USER_H
#define PROFILE_USER_H

#include <QDialog>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class profile_User;
}

class profile_User : public QDialog
{
    Q_OBJECT

public:
    explicit profile_User(const QString & key_username ,QWidget *parent = 0);
    ~profile_User();

private slots:
    void on_PB_add_new_button_clicked();

    void on_PB_star_tasks_clicked();

    void on_pushButton_clicked();

    void on_PB_show_coworkers_clicked();

    void on_PB_back_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::profile_User *ui;
    QString Key_Username ;

    void show_info_in_tree() ;

    void check_the_date() ;

    void handleCheckboxStateChanged(QTreeWidgetItem* item, int column) ;
};

#endif // PROFILE_USER_H
