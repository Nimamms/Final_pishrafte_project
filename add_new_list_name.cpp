#include "add_new_list_name.h"
#include "ui_add_new_list_name.h"
#include "profile_user.h"
#include "add_tasks_to_new_list.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

add_new_list_name::add_new_list_name(const QString & key_username , QWidget *parent) :
    QDialog(parent)
  , ui(new Ui::add_new_list_name)
  , P_key_Username(key_username)
{
    ui->setupUi(this);
}

add_new_list_name::~add_new_list_name()
{
    delete ui;
}



void add_new_list_name::on_PB_back_clicked()
{
    profile_User * profile = new profile_User(P_key_Username) ;
    this->hide();
    profile->show();
}

void add_new_list_name::on_PB_next_clicked()
{
    QString List_title = ui->LE_Title->text() ;
    if (List_title == "")
        ui->Warniing_label->setText("Tile of list is required");
    else if (ui->RadioB_cyan->isChecked() || ui->RadioB_red->isChecked() || ui->RadioB_white->isChecked())                      //accepted for next button
    {
        ui->Warniing_label->setText("");

                                                //add to sql

        QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
        db.setDatabaseName("Todolist_Database.sqlite");
        db.open();
        if (db.isOpen())
        {
            QSqlQuery query ;
            query.prepare("INSERT INTO Custom_Lists (User_username,List_name,Color)" "VALUES(:user_username , :list_name , :color)") ;
            query.bindValue(":user_username" , P_key_Username);
            query.bindValue(":list_name" , ui->LE_Title->text());
            if (ui->RadioB_white->isChecked())
                query.bindValue(":color" , "white");
            else if (ui->RadioB_red->isChecked())
                query.bindValue(":color" , "red");
            else
                query.bindValue(":color" , "cyan") ;
            query.exec() ;



        }
        else
        {
            QMessageBox::warning(this,"Not connected" , "Database is not connected " );
        }
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;
                                                                              //going to next page
        QString key_username = P_key_Username ;
        QString list_name = ui->LE_Title->text() ;
        add_tasks_to_new_list * add_tasks = new add_tasks_to_new_list(key_username , list_name) ;
        this->hide();
        add_tasks->show();

    }
    else
        ui->Warniing_label->setText("choose one of the color for your list ");



}
