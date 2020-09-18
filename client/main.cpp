#include <QCoreApplication>
#include <client.h>
#include <user.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client_1;
    user user_1;

    user_1.write_message();
    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());

    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());
    client_1.send_message(user_1.get_name());

    client_1.send_message(user_1.get_message());

    return a.exec();
}
