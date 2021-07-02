#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "auth_window.h"
#include "clientStuff.h"
#include "reg_window.h"
#include <QProcess>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    void display();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void receivedSomething(QString msg);
    void gotError(QAbstractSocket::SocketError err);

private slots:
    void authorizeUser();
    void back_to_auth();
    void startgame();
    void reg();
    void go_to_reg();

private:
    auth_window ui_Auth;
    reg_window ui_Reg;
    Ui::MainWindow *ui;
    ClientStuff *client;
};

#endif // MAINWINDOW_H
