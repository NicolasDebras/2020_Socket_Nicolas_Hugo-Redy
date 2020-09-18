#ifndef SERVEUR_H
#define SERVEUR_H

#include <QObject>
#include <QtNetwork>
#include <iostream>

class serveur: public QObject
{
    Q_OBJECT
private:
    QTcpServer *m_tcp_server;//Lasocketgénéral
    QTcpSocket *m_socket_client;//Lasocketclient
    QNetworkSession *m_network_session;
    quint16 m_blockSize;

public:
    serveur();
    void send_message(QString texte);

public slots:
    void sessionOuverte();
    void connexionClient();
    void lireTexte();


};

#endif // SERVEUR_H
