#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>

Dialog::Dialog(const QString & key_username ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
  , Key_Username(key_username)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_PB_continue_clicked()
{

    QSqlDatabase db = QSqlDatabase ::addDatabase("QSQLITE") ;
    db.setDatabaseName("Todolist_Database.sqlite");
    db.open();
    if (db.isOpen())
    {
        QSqlQuery query ;
        query.prepare("SELECT * FROM Tasks WHERE User_Username = :user_username AND List_name = :listname") ;
        query.bindValue(":user_username" , Key_Username);
        query.bindValue(":listname" , ui->LE_namelist->text());
        query.exec() ;

        QString filename = QFileDialog::getSaveFileName((QWidget *)0, "Export PDF" , QString(), "*.pdf");
        if (QFileInfo(filename).suffix().isEmpty()){ filename.append(".pdf") ;}

        QPrinter printer( QPrinter::PrinterResolution) ;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(filename);
        QTextDocument document;

        while(query.next())
        {
            QString taskName = query.value(2).toString() ;
            QString taskDate = query.value(5).toString();
            QString taskExplanation = query.value(6).toString();
            QString taskPerson = query.value(7).toString();

            document.setHtml("<p>Column 1: " + ui->LE_namelist->text() + "   "+ Key_Username+ "   "  + taskName +  " " + taskDate +" "+ taskExplanation + "  " +taskPerson +"</p>");
            document.print(&printer);



        }


        QMessageBox::information(this, "PDF Export", "List information exported to PDF successfully!");
    }

    db.close();
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    //=============================================================

}
