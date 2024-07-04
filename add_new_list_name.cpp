#include "add_new_list_name.h"
#include "ui_add_new_list_name.h"
#include "profile_user.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

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
        QSqlQuery query ;
//        query.prepare("INSERT INTO ")



    }
    else
        ui->Warniing_label->setText("choose one of the color for your list ");



}
