#include "serveur.h"

serveur::serveur()
{
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

    m_socket_client = m_tcp_server->nextPendingConnection();

    connect( m_socket_client, SIGNAL(readyRead()), this,
             SLOT(lireTexte()));
}
void serveur::lireTexte()
{
    QDataStream in(m_socket_client);
    in.setVersion(QDataStream::Qt_4_0);
    if (m_blockSize == 0) {
        if (m_socket_client->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> m_blockSize;
    }
    if (m_socket_client->bytesAvailable() < m_blockSize)
        return;
    QString texte;
    in >> texte;
    m_blockSize = 0;
}
