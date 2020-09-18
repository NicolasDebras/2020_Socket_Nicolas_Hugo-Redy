#include "user.h"

#include <cstdio>
using namespace std;

user::user()
{
    char name[35];
    cin >> name;
    m_name = name;
}

void user::write_message() {

    char message[120];
    cin >> message;
    m_message = message;
}

QString user::get_name() {
    return m_name;
}
QString user::get_message() {
    return m_message;
}
