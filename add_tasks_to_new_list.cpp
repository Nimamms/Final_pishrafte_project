#include "add_tasks_to_new_list.h"
#include "ui_add_tasks_to_new_list.h"
#include "profile_user.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

add_tasks_to_new_list::add_tasks_to_new_list(const QString & key_username ,const QString & List_name ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_tasks_to_new_list)
   ,P_key_username(key_username)
   ,P_List_name(List_name)
{
    ui->setupUi(this);
}

add_tasks_to_new_list::~add_tasks_to_new_list()
{
    delete ui;
}

void add_tasks_to_new_list::on_PB_add_task_clicked()
{
    if (ui->LE_name->text()=="")
    {
        ui->Warning_label->setText("Name of the task is required");
        return ;
    }
    QString time_text =ui->LE_Time->text() ;
    if (time_text.size()!=10)
    {
        ui->Warning_label->setText("time format is not correct");
        return ;
    }
    if (ui->LE_functor->text()=="")                                                      //if functor was empty be he / she
    {
        QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
        db.setDatabaseName("Todolist_Database.sqlite");
        db.open();
        if (db.isOpen())
        {
            QSqlQuery query ;
            query.prepare("INSERT INTO Tasks (User_Username,List_name,Name,is_stared,is_finished,Date,Explenation,person_accept)"
                          "VALUES(:user_Username,:list_name,:name,:is_stared,:is_finished,:date,:explenation,:person_accept)") ;
            query.bindValue(":user_Username" , P_key_username);
            query.bindValue(":list_name" , P_List_name);
            query.bindValue(":name" , ui->LE_name->text());
            query.bindValue(":is_stared" , 0);                      //0 means false
            query.bindValue(":is_finished" , 0);
            query.bindValue(":date" , ui->LE_Time->text());
            query.bindValue(":explenation" , ui->LE_description->text());
            query.bindValue(":person_accept" , P_key_username);
            query.exec() ;
            db.close();
            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;
            QMessageBox::information(this , "Done" , "your Task added successfully ");
            return ;

        }
    }
                                                             //search for functors
    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
    db.setDatabaseName("Todolist_Database.sqlite");
    db.open();
    if (db.isOpen())
    {
        QSqlQuery query ;
        QString User_search = ui->LE_functor->text() ;
        query.prepare("SELECT Username FROM Users WHERE Username = ?") ;
        query.bindValue(0,User_search);
        if(query.exec())
        {
            if(query.next())
            {
                QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
                db.setDatabaseName("Todolist_Database.sqlite");
                db.open();
                if (db.isOpen())
                {
                    QSqlQuery query ;
                    query.prepare("INSERT INTO Tasks (User_Username,List_name,Name,is_stared,is_finished,Date,Explenation,person_accept)"
                                  "VALUES(:user_Username,:list_name,:name,:is_stared,:is_finished,:date,:explenation,:person_accept)") ;
                    query.bindValue(":user_Username" , P_key_username);
                    query.bindValue(":list_name" , P_List_name);
                    query.bindValue(":name" , ui->LE_name->text());
                    query.bindValue(":is_stared" , 0);                      //0 means false
                    query.bindValue(":is_finished" , 0);
                    query.bindValue(":date" , ui->LE_Time->text());
                    query.bindValue(":explenation" , ui->LE_description->text());
                    query.bindValue(":person_accept" , ui->LE_functor->text());
                    query.exec() ;
                    db.close();
                    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;
                    QMessageBox::information(this , "Done" , "your Task added successfully ");
                    ui->LE_name->clear();
                    ui->LE_Time->clear();
                    ui->LE_functor->clear();
                    ui->LE_description->clear();

                    return ;

                }
            }
            else
            {
                QMessageBox::warning(this, "Error", "User not found ") ;
            }
        }
        else
        {
              QMessageBox::warning(this, "Error", "Failed to execute the search query: ") ;
        }


    }


}

void add_tasks_to_new_list::on_PB_finish_clicked()
{
    profile_User * profile = new profile_User(P_key_username) ;
    this->hide();
    profile->show();
}
