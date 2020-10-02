#ifndef CLIENT_W_H
#define CLIENT_W_H

#include <QMainWindow>
#include <Client_serv.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE



class Client_w : public QMainWindow
{
    Q_OBJECT

public:
    Client_w(QWidget *parent = nullptr);
    ~Client_w();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::Client *ui;
    QString message;
    QString name;
    Client_serv client;

};
#endif // CLIENT_W_H
