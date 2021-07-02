#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /* db.setHostName("Base");
        db.setPort(3306);
        db.setDatabaseName("Name");
        db.setUserName("admin");
        db.setPassword("Password");
        db.open();
        */
    MainWindow w;

    return a.exec();
}
