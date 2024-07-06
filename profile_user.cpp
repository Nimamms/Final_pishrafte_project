#include "profile_user.h"
#include "ui_profile_user.h"
#include "add_new_list_name.h"
#include "QMessageBox"
#include <QPushButton>
#include <QDateTime>
#include "dialog.h"
#include "mainwindow.h"

profile_User::profile_User(const QString & key_username ,QWidget *parent) :
    QDialog(parent)
    , ui(new Ui::profile_User)
    , Key_Username(key_username)
{
    ui->setupUi(this);
    ui->Welcome_label->setText( profile_User ::Key_Username ) ;
    show_info_in_tree();
    check_the_date();
}

profile_User::~profile_User()
{
    delete ui;
}

void profile_User::show_info_in_tree()
{
    ui->Tree_show->setColumnCount(1);
    QStringList labels ;
    labels<<"to do list " ;
    ui->Tree_show->setHeaderLabels(labels);

                                                                                            //Assumption Titles ( This week , This month )


    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
    db.setDatabaseName("Todolist_Database.sqlite");
    db.open();
    if (db.isOpen())
    {
        QSqlQuery query ;
        query.prepare("SELECT List_name FROM custom_Lists WHERE user_username = :user_username") ;
        query.bindValue(":user_username" , Key_Username);
        query.exec() ;
        while(query.next())
        {
            QString List_name = query.value(0).toString() ;
            QTreeWidgetItem * root = new QTreeWidgetItem(ui->Tree_show) ;
            root->setText(0,List_name);
            root->setIcon(0 , QIcon( ":/images/folder.png"));
            ui->Tree_show->addTopLevelItem(root);

            QSqlQuery query2 ;
            query2.prepare("SELECT Name FROM Tasks WHERE user_username = :user_username AND List_name = :list_name") ;
            query2.bindValue(":user_username", Key_Username);
            query2.bindValue(":list_name" , List_name);
            query2.exec() ;
            while (query2.next())                                                                      //Tasks name(Title)
            {
                QString Name_task = query2.value(0).toString() ;
                QTreeWidgetItem * child = new QTreeWidgetItem();
                child->setText(0 , Name_task );
                child->setIcon(0 , QIcon( ":/images/Circle_34541.png"));
                child->setCheckState(0,Qt::Unchecked);
                QPushButton * PB_edit =  new QPushButton("edit") ;
                ui->Tree_show->setItemWidget(child , 1 ,PB_edit );
                root->addChild(child);

                QSqlQuery query3 ;
                query3.prepare("SELECT * FROM Tasks WHERE user_username = :user_username AND List_name = :list_name AND Name = :name_task ") ;
                query3.bindValue(":user_username", Key_Username);
                query3.bindValue(":list_name" , List_name);
                query3.bindValue(":name_task" , Name_task);
                query3.exec() ;
                while (query3.next())
                {
                    QString is_stared = query3.value(3).toString() ;
                    QTreeWidgetItem * tasks_is_stared = new QTreeWidgetItem();
                    tasks_is_stared->setText(0," make it stared ?");
                    if (is_stared=="0")
                        tasks_is_stared->setCheckState(0,Qt::Unchecked);
                    else
                        tasks_is_stared->setCheckState(0,Qt::Checked);
                    child->addChild(tasks_is_stared);

                    QString Date = query3.value(5).toString() ;
                    QTreeWidgetItem * tasks_date = new QTreeWidgetItem();
                    tasks_date->setText(0,Date);
                    child->addChild(tasks_date);

                    QString EXplenation = query3.value(6).toString() ;
                    QTreeWidgetItem * Task_EXplenation = new QTreeWidgetItem();
                    Task_EXplenation->setText(0,EXplenation);
                    child->addChild(Task_EXplenation);


                    QString person_accepted = query3.value(7).toString() ;
                    QTreeWidgetItem * Task_person = new QTreeWidgetItem();
                    Task_person->setText(0,person_accepted);
                    child->addChild(Task_person);


                }


            }
        }


    }
    else
        QMessageBox::warning(this,"Not connected" , "Database is not connected ") ;
    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;

}

void profile_User::check_the_date()
{
    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
    db.setDatabaseName("Todolist_Database.sqlite");
    db.open();
    if (db.isOpen())
    {
        QSqlQuery query ;
        query.prepare("SELECT * FROM Tasks WHERE user_username = :user_username") ;
        query.bindValue(":user_username" , Key_Username);
        query.exec() ;
        while (query.next())
        {
            QString time_tasks = query.value(6).toString();
            QDate date = QDate::fromString(time_tasks , "yyyy-MM-dd") ;
            QString task_name = query.value(3).toString();

            if (QDate::currentDate() == date)
            {
                QMessageBox::information(this , "its Today" ,  task_name ) ;
            }

        }
    }

}

void profile_User::on_PB_add_new_button_clicked()
{
    QString key_username = ui->Welcome_label->text();
    add_new_list_name * make_new_list = new add_new_list_name(key_username) ;
    this->hide();
    make_new_list->show();
}

void profile_User::on_PB_star_tasks_clicked()
{
    ui->Tree_show->clear();


    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
    db.setDatabaseName("Todolist_Database.sqlite");
    db.open();
    if (db.isOpen())
    {
        QSqlQuery query ;
        query.prepare("SELECT List_name FROM custom_Lists WHERE user_username = :user_username" ) ;
        query.bindValue(":user_username" , Key_Username);
        query.exec() ;
        while(query.next())
        {
            QString List_name = query.value(0).toString() ;
            QTreeWidgetItem * root = new QTreeWidgetItem(ui->Tree_show) ;
            root->setText(0,List_name);
            root->setIcon(0 , QIcon( ":/images/folder.png"));
            ui->Tree_show->addTopLevelItem(root);

            QSqlQuery query2 ;
            query2.prepare("SELECT Name FROM Tasks WHERE user_username = :user_username AND List_name = :list_name AND is_stared ==:is_stared") ;
            query2.bindValue(":user_username", Key_Username);
            query2.bindValue(":list_name" , List_name);
            query2.bindValue(":is_stared" , 1);
            query2.exec() ;
            while (query2.next())                                                                      //Tasks name(Title)
            {
                QString Name_task = query2.value(0).toString() ;
                QTreeWidgetItem * child = new QTreeWidgetItem();
                child->setText(0 , Name_task );
                child->setIcon(0 , QIcon( ":/images/Circle_34541.png"));
                child->setCheckState(0,Qt::Unchecked);
                QPushButton * PB_edit =  new QPushButton("edit") ;
                ui->Tree_show->setItemWidget(child , 1 ,PB_edit );
                root->addChild(child);

                QSqlQuery query3 ;
                query3.prepare("SELECT * FROM Tasks WHERE user_username = :user_username AND List_name = :list_name AND Name = :name_task  AND is_stared ==:is_stared ") ;
                query3.bindValue(":user_username", Key_Username);
                query3.bindValue(":list_name" , List_name);
                query3.bindValue(":name_task" , Name_task);
                query3.bindValue(":is_stared" , 1);
                query3.exec() ;
                while (query3.next())
                {
                    QString is_stared = query3.value(3).toString() ;
                    QTreeWidgetItem * tasks_is_stared = new QTreeWidgetItem();
                    tasks_is_stared->setText(0," make it stared ?");
                    if (is_stared=="0")
                        tasks_is_stared->setCheckState(0,Qt::Unchecked);
                    else
                        tasks_is_stared->setCheckState(0,Qt::Checked);
                    child->addChild(tasks_is_stared);

                    QString Date = query3.value(5).toString() ;
                    QTreeWidgetItem * tasks_date = new QTreeWidgetItem();
                    tasks_date->setText(0,Date);
                    child->addChild(tasks_date);

                    QString EXplenation = query3.value(6).toString() ;
                    QTreeWidgetItem * Task_EXplenation = new QTreeWidgetItem();
                    Task_EXplenation->setText(0,EXplenation);
                    child->addChild(Task_EXplenation);


                    QString person_accepted = query3.value(7).toString() ;
                    QTreeWidgetItem * Task_person = new QTreeWidgetItem();
                    Task_person->setText(0,person_accepted);
                    child->addChild(Task_person);


                }


            }
        }


    }
    else
        QMessageBox::warning(this,"Not connected" , "Database is not connected ") ;
    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;
}

void profile_User::on_pushButton_clicked()
{
    ui->Tree_show->clear();
    show_info_in_tree();
}

void profile_User::on_PB_show_coworkers_clicked()
{
    ui->Tree_show->clear();

    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
    db.setDatabaseName("Todolist_Database.sqlite");
    db.open();
    if (db.isOpen())
    {
        QSqlQuery query ;
        query.prepare("SELECT person_accept FROM Tasks WHERE User_Username = :user_username") ;
        query.bindValue(":user_username" , Key_Username);
        query.exec() ;
        while(query.next())
        {
            QString person_accept = query.value(0).toString() ;
            QTreeWidgetItem * root = new QTreeWidgetItem(ui->Tree_show) ;
            root->setText(0,person_accept);
            root->setIcon(0 , QIcon( ":/images/folder.png"));
            ui->Tree_show->addTopLevelItem(root);

            QSqlQuery query2 ;
            query2.prepare("SELECT Name FROM Tasks WHERE user_username = :user_username AND person_accept = :person_accept") ;
            query2.bindValue(":user_username", Key_Username);
            query2.bindValue(":person_accept" ,person_accept );
            query2.exec() ;
            while (query2.next())                                                                      //Tasks name(Title)
            {
                QString Name_task = query2.value(0).toString() ;
                QTreeWidgetItem * child = new QTreeWidgetItem();
                child->setText(0 , Name_task );
                child->setIcon(0 , QIcon( ":/images/Circle_34541.png"));
                child->setCheckState(0,Qt::Unchecked);
                root->addChild(child);





            }
        }


    }
    else
        QMessageBox::warning(this,"Not connected" , "Database is not connected ") ;
    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;

}

void profile_User::on_PB_back_clicked()
{
    MainWindow * login_page = new MainWindow() ;
    this->hide();
    login_page->show();
}

void profile_User::on_pushButton_2_clicked()
{
}

void profile_User::on_pushButton_3_clicked()
{
    Dialog * print_PDF = new Dialog(Key_Username) ;
    this->hide();
    print_PDF->show();
}
