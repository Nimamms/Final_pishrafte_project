#include "profile_user.h"
#include "ui_profile_user.h"
#include "add_new_list_name.h"

profile_User::profile_User(const QString & key_username ,QWidget *parent) :
    QDialog(parent)
    , ui(new Ui::profile_User)
    , Key_Username(key_username)
{
    ui->setupUi(this);
    ui->Welcome_label->setText( profile_User ::Key_Username ) ;
    show_info_in_tree();
}

profile_User::~profile_User()
{
    delete ui;
}

void profile_User::show_info_in_tree()
{
//    ui->Tree_show->setHeaderItem(2);
//    QStringList labels ;
//    labels<<"This Weak" << "This month" ;
//    ui->Tree_show->setHeaderLabels(labels);

                                                                                            //Assumption Titles ( This week , This month )
    QTreeWidgetItem * root = new QTreeWidgetItem(ui->Tree_show) ;
    root->setText(0,"This Week");
    ui->Tree_show->addTopLevelItem(root);
    QTreeWidgetItem * root2 = new QTreeWidgetItem(ui->Tree_show) ;
    root2->setText(0,"This month");
    ui->Tree_show->addTopLevelItem(root2);

    QTreeWidgetItem * root_tasks = new QTreeWidgetItem() ;
    root_tasks->setText(0 , "name task");
    root_tasks->setCheckState(0,Qt::Unchecked);
    root->addChild(root_tasks);
    QTreeWidgetItem * root_tasks2 = new QTreeWidgetItem() ;
    root_tasks2->setText(0 , "name task2");
    root_tasks2->setCheckState(0,Qt::Unchecked);
    root->addChild(root_tasks2);



}

void profile_User::on_PB_add_new_button_clicked()
{
    QString key_username = ui->Welcome_label->text();
    add_new_list_name * make_new_list = new add_new_list_name(key_username) ;
    this->hide();
    make_new_list->show();
}
