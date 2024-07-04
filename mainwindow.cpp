#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "profile_user.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //set background texts to lineedits
    ui->setupUi(this);
    ui->LE_signup_name->setPlaceholderText(QString("Name "));
    ui->LE_signup_username->setPlaceholderText(QString("Username "));
    ui->LE_signup_password->setPlaceholderText(QString("New password "));
    ui->LE_username->setPlaceholderText(QString("Username"));
    ui->LE_password->setPlaceholderText(QString("password"));


    //hide sign up
    ui->LE_signup_name->setHidden(true);
    ui->LE_signup_username->setHidden(true);
    ui->LE_signup_password->setHidden(true);
    ui->PB_sign_up->setHidden(true);

    //center all background texts
    ui->LE_username->setAlignment(Qt::AlignCenter);
    ui->LE_password->setAlignment(Qt::AlignCenter);
    ui->LE_signup_name->setAlignment(Qt::AlignCenter);
    ui->LE_signup_username->setAlignment(Qt::AlignCenter);
    ui->LE_signup_password->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PB_sign_up_clicked()
{
//    QSqlQuery query ;
//    query.prepare("INSERT INTO Users(Name , Username , Password)"
//                  "VALUES(:name , :username , :password)") ;
}

void MainWindow::on_dont_have_account_stateChanged(int arg1)
{
    if(ui->dont_have_account->isChecked())
    {
        ui->LE_signup_name->show();
        ui->LE_signup_username->show();
        ui->LE_signup_password->show();
        ui->PB_sign_up->show();
    }
    else
    {
        ui->LE_signup_name->setHidden(true);
        ui->LE_signup_username->setHidden(true);
        ui->LE_signup_password->setHidden(true);
        ui->PB_sign_up->setHidden(true);
    }

}

void MainWindow::on_PB_login_clicked()
{

    //check line edits
    if (ui->LE_username->text().isEmpty() || ui->LE_password->text().isEmpty())
    {
        QMessageBox::warning(this , "Warning" , "your blank is empty") ;
    }
    QSqlDatabase db  = QSqlDatabase :: addDatabase("QSQLITE") ;
    bool flag = true ;
    db.setDatabaseName("Todolist_Database.sqlite");
    db.open() ;
    if(db.isOpen())
    {
        QSqlQuery query ;
        query.prepare("SELECT Password FROM Users WHERE Username = :username") ;
        query.bindValue(":username" , ui->LE_username->text());
        query.exec();
        while(query.next())
        {
            if (query.value(0).toString() !=ui->LE_password->text())
            {
                ui->LA_error_login->setText("username not exist");
            }
            else
            {
                ui->LA_error_login->setText("");
                flag = false ;
            }
        }
        if (flag==true)
            ui->LA_error_login->setText("password is wrong");
    }
    else
    {
        QMessageBox::warning(this , "Warning" , "database isnt connected") ;
    }
    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection) ;


    if (flag == false ) //username and password were correct
    {
        QString key_username = ui->LE_username->text() ;
        QMessageBox::information(this , "Welcome" , "you sign in successfully") ;
        profile_User * profile = new profile_User(key_username) ;
        this->hide();
        profile->show();

    }

}
