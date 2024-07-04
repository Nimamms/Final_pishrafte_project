#ifndef ADD_NEW_LIST_NAME_H
#define ADD_NEW_LIST_NAME_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class add_new_list_name;
}

class add_new_list_name : public QDialog
{
    Q_OBJECT

public:
    explicit add_new_list_name(const QString & key_username , QWidget *parent = 0);
    ~add_new_list_name();

private slots:



    void on_PB_back_clicked();

    void on_PB_next_clicked();

private:
    Ui::add_new_list_name *ui;
    QString P_key_Username ;
};

#endif // ADD_NEW_LIST_NAME_H
