#ifndef USER_H
#define USER_H
#include <QString>


class User
{
private :
    QString P_name ;
    QString P_username ;
    QString P_password ;

public:
    User( const QString Name , const QString Username , const QString Password );

    const QString & Getname() const ;
    const QString & Getusername() const ;
    const QString & Getpassword() const ;

    void Setname(QString & name) ;
    void Setusername(QString & username) ;
    void Setpassword(QString & password) ;


};

#endif // USER_H
