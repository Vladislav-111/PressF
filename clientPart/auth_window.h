#ifndef AUTH_WINDOW_H
#define AUTH_WINDOW_H

#include <QWidget>

namespace Ui {
class auth_window;
}

class auth_window : public QWidget
{
    Q_OBJECT

public:
    explicit auth_window(QWidget *parent = nullptr);
    ~auth_window();                                                       //прототип деструктора
    QString getLogin();
    QString getPass();


signals:
    void login_button_clicked();
    void register_button_clicked();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_loginPushButton_clicked();

    void on_registerPushButton_2_clicked();


private:
    Ui::auth_window *ui;
    QString m_username;
    QString m_userpass;
    friend class mainwindow;

};

#endif // AUTH_WINDOW_H
