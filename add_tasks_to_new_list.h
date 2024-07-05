#ifndef ADD_TASKS_TO_NEW_LIST_H
#define ADD_TASKS_TO_NEW_LIST_H

#include <QDialog>

namespace Ui {
class add_tasks_to_new_list;
}

class add_tasks_to_new_list : public QDialog
{
    Q_OBJECT

public:
    explicit add_tasks_to_new_list(const QString & key_username ,const QString & List_name ,QWidget *parent = 0);
    ~add_tasks_to_new_list();

private slots:
    void on_PB_add_task_clicked();

    void on_PB_finish_clicked();

private:
    Ui::add_tasks_to_new_list *ui;
    QString P_key_username ;
    QString P_List_name ;
};

#endif // ADD_TASKS_TO_NEW_LIST_H
