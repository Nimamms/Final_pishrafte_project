#include "profile_user.h"
#include "ui_profile_user.h"

profile_User::profile_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile_User)
{
    ui->setupUi(this);
}

profile_User::~profile_User()
{
    delete ui;
}
