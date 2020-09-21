#include "serveur.h"
#include <string>

serveur::serveur()
{
    m_nbclients = 0;
    m_blockSize = 0;
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config = manager.defaultConfiguration();
    m_network_session = new QNetworkSession(config, this);


    connect( m_network_session, SIGNAL(opened()), this,
             SLOT(sessionOuverte()) );

    m_network_session->open();


    connect( m_tcp_server, SIGNAL(newConnection()), this,
             SLOT(connexionClient()) );

}

void serveur::sessionOuverte()
{
    m_tcp_server = new QTcpServer(this);

    if (!m_tcp_server->listen(QHostAddress::Any, 53000))
    {
        std::cout << "Le serveur n'a pas été correctement lance." << std::endl;
    }
    else
    {
        std::cout << "Le serveur est pret \n\nIP: " <<
                     m_tcp_server->serverAddress().toString().toStdString()
                  << std::endl << "port: " << m_tcp_server->serverPort()
                  << std::endl
                  << "Lancez l'application Client maintenant."
                  << std::endl;
    }
}
void serveur::connexionClient()
{

    m_socket_client[m_nbclients] = m_tcp_server->nextPendingConnection();
    std::cout << "affichage client" << std::endl;
    for (int i = 0; i != 100; i++)
        connect( m_socket_client[m_nbclients], SIGNAL(readyRead()), this,
                 SLOT(lireTexte()));
    m_nbclients++;

}

void serveur::lireTexte()
{
    QTcpSocket* socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);
    if (m_blockSize == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> m_blockSize;
    }
    if (socket->bytesAvailable() < m_blockSize)
        return;
    QString texte;
    in >> texte;
    std::cout << "MESSAGE ENVOYER ::\n" << texte.toStdString() << std::endl;
    translation_message(texte);
    m_blockSize = 0;
    //lireTexte();
}
void serveur::translation_message(QString texte) {

    int i = 0;

    while (texte.at(i) != '?' && texte.at(i+1) != '0' && texte.at(i+2) != '?') {
        i++;
    }
    std::string text_convertion = texte.toStdString();
    std::string message = text_convertion.substr(0, i+2);

    text_convertion = texte.toStdString();
    std::size_t pos = text_convertion.find("?0?");
    std::string autor_message = text_convertion.substr(pos);
    autor_message = autor_message.substr(3, autor_message.length());

    std::string final_message = "Message envoye par : ";
    final_message = final_message + autor_message;
    final_message = final_message + "\n";
    final_message = final_message + message;
    send_message(QString::fromStdString(final_message));

}
void serveur::send_message(QString texte) {

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << texte;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
//    for( int i = 0; i < m_nbclients; i++ )
        m_socket_client[0]->write(block);
        m_socket_client[1]->write(block);
}

