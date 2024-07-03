/********************************************************************************
** Form generated from reading UI file 'profile_user.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_USER_H
#define UI_PROFILE_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_profile_User
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *profile_User)
    {
        if (profile_User->objectName().isEmpty())
            profile_User->setObjectName(QStringLiteral("profile_User"));
        profile_User->resize(350, 600);
        profile_User->setStyleSheet(QLatin1String("#profile_User\n"
"{\n"
"background-image : url(:/images/first back_ground.png)\n"
"}"));
        listWidget = new QListWidget(profile_User);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(25, 50, 301, 531));

        retranslateUi(profile_User);

        QMetaObject::connectSlotsByName(profile_User);
    } // setupUi

    void retranslateUi(QDialog *profile_User)
    {
        profile_User->setWindowTitle(QApplication::translate("profile_User", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class profile_User: public Ui_profile_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_USER_H
