#include "user.h"
#include "client.h"

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
    message = message +  "User ";
    message = message +  m_name.toStdString();
    std::cout << "\n" << message << std::endl;
    m_message = QString::fromStdString(message);
    m_client.send_message(m_message);
}

void user::menu() {

    std::cout << "- - Menu - -\n(taper le numero pour chosir) :\n1 : Envoyer un message\n2 : Quitter la conservation\n3 : Plus d'option " << endl;
    string message;
    getline(cin, message);
    getline(cin, message);

    if (message.at(0) == '1') {
        std::cout << "- - ENVOIE DE MESSAGE - -" << endl;
        write_message();
    }
    else if (message.at(0) == '2') {
        std::cout << "- - FERMETURE DU PROGRAMME - -" << endl;
    }
    else if (message.at(0) == '3') {
        std::cout << "- - OPTION DU PROGRAMME - -" << endl;
    }
    else
        menu();
}

QString user::get_name() {
    return m_name;
}
QString user::get_message() {
    return m_message;
}
