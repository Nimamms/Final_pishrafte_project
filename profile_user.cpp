#include "profile_user.h"
#include "ui_profile_user.h"

profile_User::profile_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile_User)
{
    ui->setupUi(this);
    show_info_in_tree();
}

profile_User::~profile_User()
{
    delete ui;
}

void profile_User::show_info_in_tree()
{
    ui->Tree_show->setColumnCount(2);
    QStringList labels ;
    labels<<"This Weak" << "This month" ;
    ui->Tree_show->setHeaderLabels(labels);

    QTreeWidgetItem * root = new QTreeWidgetItem(ui->Tree_show) ;
    root->setText(0,"test1");
    root->setText(1,"test2");
    ui->Tree_show->addTopLevelItem(root);
}
