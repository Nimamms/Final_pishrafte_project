#ifndef PROFILE_USER_H
#define PROFILE_USER_H

#include <QDialog>

namespace Ui {
class profile_User;
}

class profile_User : public QDialog
{
    Q_OBJECT

public:
    explicit profile_User(QWidget *parent = 0);
    ~profile_User();

private:
    Ui::profile_User *ui;
};

#endif // PROFILE_USER_H
