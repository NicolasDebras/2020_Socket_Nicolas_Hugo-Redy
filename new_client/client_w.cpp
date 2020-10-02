#include "client_w.h"
#include "ui_client_w.h"
#include <Client_serv.h>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


Client_w::Client_w(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    name = "NOM DE BASES";
    ui->setupUi(this);

}

Client_w::~Client_w()
{
    delete ui;
}


void Client_w::on_pushButton_clicked()
{
    QString message;
    message = ui->textEdit->toPlainText();

    string message_trans;
    message_trans = message.toStdString();
    message_trans = message_trans +  "?0?";
    message_trans = message_trans +  name.toStdString();
    message = QString::fromStdString(message_trans);
    client.send_message(message);

}
void Client_w::on_pushButton_2_clicked()
{
    ui->label_message->setText(client.get_recu(0));
    ui->label_dernier->setText(client.get_recu(1));
}

void Client_w::on_pushButton_3_clicked()
{
    name = ui->textEdit_2->toPlainText();
}
