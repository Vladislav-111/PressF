#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    client = new ClientStuff("localhost", 6547);

    connect(&ui_Auth,SIGNAL(login_button_clicked()),                                 //соединение сигнала кнопки регистрации экземпляра окна авторизации
            this,SLOT(authorizeUser()));
    connect(&ui_Auth,SIGNAL(register_button_clicked()),
            this,SLOT(go_to_reg()));

    connect(&ui_Reg,SIGNAL(back_clicked()),
            this,SLOT(back_to_auth()));

    connect(&ui_Reg,SIGNAL(register_button_clicked2()),
            this,SLOT(reg()));

    connect(client->tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(gotError(QAbstractSocket::SocketError)));

     client->connect2host();
}

void MainWindow::startgame()
{
     qDebug() << "start";
     QProcess::startDetached("../PressF/PressF.exe");
}


void MainWindow::back_to_auth()
{
    ui_Auth.show();
    ui_Reg.hide();
}
void MainWindow::reg()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    QString s = "register "+ui_Reg.getName()+" "+ui_Reg.getPass()+" "+ui_Reg.getConf();
    out << quint16(0) <<s;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    client->tcpSocket->write(arrBlock);

}
void MainWindow::go_to_reg()
{
    ui_Auth.hide();
    ui_Reg.show();
}
void MainWindow::authorizeUser()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    QString s = "login "+ui_Auth.getLogin()+" "+ui_Auth.getPass();
    out << quint16(0) <<s;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    client->tcpSocket->write(arrBlock);


}
MainWindow::~MainWindow()
{
    delete client;
    delete ui;
}
void MainWindow::display()                                                              //реализация пользотвальского метода отображения главного окна
{
    ui_Auth.show();                                                                     //отобразить окно авторизации
}

void MainWindow::receivedSomething(QString msg)
{

    qDebug() << msg;
    if(msg=="pass"){
        ui_Auth.hide();
        this->startgame();
       }
    if(msg == "successfull registraion user"){
        ui_Reg.hide();
        this->startgame();
    }


}


void MainWindow::gotError(QAbstractSocket::SocketError err)
{
    //qDebug() << "got error";
    QString strError = "unknown";
    switch (err)
    {
        case 0:
            strError = "Connection was refused";
            break;
        case 1:
            strError = "Remote host closed the connection";
            break;
        case 2:
            strError = "Host address was not found";
            break;
        case 5:
            strError = "Connection timed out";
            break;
        default:
            strError = "Unknown error";
    }
}


