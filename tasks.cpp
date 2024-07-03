#include "tasks.h"

Tasks::Tasks(const QString name , const QString time , const QString description , QString functor)
{
    P_name = name ;
    P_time = time ;
    P_description =description ;
    P_functor = functor ;
}


void Tasks::setname(QString & name)
{
    P_name = name ;
}

void Tasks::set_time(QString & time)
{
    P_time = time ;
}

void Tasks::set_description(QString description)
{
    P_description = description ;
}

void Tasks::set_functor(QString functor)
{
    P_functor = functor ;
}
