#ifndef USER_H
#define USER_H

#include <iostream>
#include <QString>


class user
{
private:
    QString m_name;
    QString m_message;

public:
    user();
    void write_message();
    QString get_name();
    QString get_message();
};

#endif // USER_H
