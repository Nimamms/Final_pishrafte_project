/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCheckBox *dont_have_account;
    QLineEdit *LE_username;
    QLineEdit *LE_password;
    QPushButton *PB_login;
    QLineEdit *LE_signup_username;
    QLineEdit *LE_signup_password;
    QPushButton *PB_sign_up;
    QLineEdit *LE_signup_name;
    QLabel *LA_error_login;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(350, 600);
        MainWindow->setStyleSheet(QLatin1String("#MainWindow{\n"
"	background-image : url(:/images/first back_ground.png);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        dont_have_account = new QCheckBox(centralWidget);
        dont_have_account->setObjectName(QStringLiteral("dont_have_account"));
        dont_have_account->setGeometry(QRect(80, 330, 151, 31));
        dont_have_account->setStyleSheet(QStringLiteral("color :rgb(255, 255, 255)"));
        LE_username = new QLineEdit(centralWidget);
        LE_username->setObjectName(QStringLiteral("LE_username"));
        LE_username->setGeometry(QRect(42, 120, 281, 31));
        LE_username->setStyleSheet(QLatin1String("font: 75 10pt \"MRT_Thameen DemiBold\";\n"
"color: rgb(60, 60, 60); \n"
"                                     background-color: #FFFFFF; \n"
"                                     border: 1px solid rgb(60, 60, 60);\n"
"                                     border-radius: 14px;"));
        LE_password = new QLineEdit(centralWidget);
        LE_password->setObjectName(QStringLiteral("LE_password"));
        LE_password->setGeometry(QRect(40, 160, 281, 31));
        LE_password->setStyleSheet(QLatin1String("font: 75 10pt \"MRT_Thameen DemiBold\";\n"
"color: rgb(60, 60, 60); \n"
"                                     background-color: #FFFFFF; \n"
"                                     border: 1px solid rgb(60, 60, 60);\n"
"                                     border-radius: 14px;"));
        PB_login = new QPushButton(centralWidget);
        PB_login->setObjectName(QStringLiteral("PB_login"));
        PB_login->setGeometry(QRect(90, 210, 181, 31));
        PB_login->setStyleSheet(QLatin1String("font: 75 14pt \"MRT_Thameen DemiBold\";\n"
"color: rgb(60, 60, 60); \n"
"                                     background-color: #F8F9D7; \n"
"                                     border: 1px solid rgb(60, 60, 60);\n"
"                                     border-radius: 14px;"));
        LE_signup_username = new QLineEdit(centralWidget);
        LE_signup_username->setObjectName(QStringLiteral("LE_signup_username"));
        LE_signup_username->setGeometry(QRect(80, 400, 211, 31));
        LE_signup_username->setStyleSheet(QLatin1String("font: 75 10pt \"MRT_Thameen DemiBold\";\n"
"color: rgb(60, 60, 60); \n"
"                                     background-color: #FFFFFF; \n"
"                                     border: 1px solid rgb(60, 60, 60);\n"
"                                     border-radius: 14px;"));
        LE_signup_password = new QLineEdit(centralWidget);
        LE_signup_password->setObjectName(QStringLiteral("LE_signup_password"));
        LE_signup_password->setGeometry(QRect(80, 440, 211, 31));
        LE_signup_password->setStyleSheet(QLatin1String("font: 75 10pt \"MRT_Thameen DemiBold\";\n"
"color: rgb(60, 60, 60); \n"
"                                     background-color: #FFFFFF; \n"
"                                     border: 1px solid rgb(60, 60, 60);\n"
"                                     border-radius: 14px;"));
        PB_sign_up = new QPushButton(centralWidget);
        PB_sign_up->setObjectName(QStringLiteral("PB_sign_up"));
        PB_sign_up->setGeometry(QRect(140, 480, 80, 21));
        PB_sign_up->setStyleSheet(QLatin1String("font: 75 12pt \"MRT_Thameen DemiBold\";\n"
"color: rgb(60, 60, 60); \n"
"                                     background-color: #F8F9D7; \n"
"                                     border: 1px solid rgb(60, 60, 60);\n"
"                                     border-radius: 10px;"));
        LE_signup_name = new QLineEdit(centralWidget);
        LE_signup_name->setObjectName(QStringLiteral("LE_signup_name"));
        LE_signup_name->setGeometry(QRect(80, 360, 211, 31));
        LE_signup_name->setStyleSheet(QLatin1String("font: 75 10pt \"MRT_Thameen DemiBold\";\n"
"color: rgb(60, 60, 60); \n"
"                                     background-color: #FFFFFF; \n"
"                                     border: 1px solid rgb(60, 60, 60);\n"
"                                     border-radius: 14px;"));
        LA_error_login = new QLabel(centralWidget);
        LA_error_login->setObjectName(QStringLiteral("LA_error_login"));
        LA_error_login->setGeometry(QRect(50, 90, 121, 31));
        LA_error_login->setStyleSheet(QLatin1String("color :rgb(255, 0, 0) ;\n"
"font: 11pt \"MS Shell Dlg 2\";"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 350, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        dont_have_account->setText(QApplication::translate("MainWindow", "dont have account !?", Q_NULLPTR));
        PB_login->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        PB_sign_up->setText(QApplication::translate("MainWindow", "sign up", Q_NULLPTR));
        LA_error_login->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
