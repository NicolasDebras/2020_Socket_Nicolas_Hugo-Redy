#include <QCoreApplication>
#include <client.h>
#include <user.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    user user_1;
    user_1.menu();

    return a.exec();
}
