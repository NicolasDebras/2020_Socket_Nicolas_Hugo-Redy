#include "user.h"

#include <cstdio>
#include <iostream>
#include <string>


using namespace std;

user::user()
{
    char name[35];
    cin >> name;
    m_name = name;
}

void user::write_message() {

    string message;
    cout << "Please, enter your message: ";
    getline(cin, message);
    getline(cin, message);
    message = message +  "User ";
    message = message +  m_name.toStdString();
    //std::cout << "\n" << message << std::endl;
    m_message = QString::fromStdString(message);
}

QString user::get_name() {
    return m_name;
}
QString user::get_message() {
    return m_message;
}
