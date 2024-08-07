#ifndef TASKS_H
#define TASKS_H
#include <QString>


class Tasks
{
private :
    QString P_name ;
    QString P_time ;
    QString P_description ;
    bool P_stared =false ;
    bool P_is_done = false ;
    QString P_functor ;        //انجام دهنده
public:
    Tasks(const QString name , const QString time , const QString description , QString functor);


    void setname(QString & name) ;
    void set_time(QString & time) ;
    void set_description(QString description) ;
    void set_functor(QString functor) ;
};

#endif // TASKS_H
