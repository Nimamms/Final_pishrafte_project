#include "user.h"

User::User( const QString Name , const QString Username , const QString Password )
{
    P_name= Name ;
    P_username = Username ;
    P_password = Password ;
}


const QString & User::Getname() const
{
    return P_name ;
}
const QString & User::Getusername() const
{
    return P_username;
}
const QString & User::Getpassword() const
{
    return P_password ;
}


void User::Setname(QString & Name)
{
    P_name = Name ;
}
void User::Setusername(QString & Username)
{
    P_username = Username ;
}
void User::Setpassword(QString & Password)
{
    P_password = Password ;
}
