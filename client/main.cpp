#include <QCoreApplication>
#include <client.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client_1;
    client_1.send_message();

    return a.exec();
}
