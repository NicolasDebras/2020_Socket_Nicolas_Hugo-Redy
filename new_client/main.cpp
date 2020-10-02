#include "client_w.h"
#include "Client_serv.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client_w w;
    w.show();
    return a.exec();
}
