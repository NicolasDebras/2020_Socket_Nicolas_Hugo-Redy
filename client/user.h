#ifndef USER_H
#define USER_H

#include <iostream>
#include <QString>
#include <client.h>

class user
{
private:
    QString m_name;
    QString m_message;
    Client m_client;

public:
    user();
    void write_message();
    void menu();
    QString get_name();
    QString get_message();
};

#endif // USER_H
