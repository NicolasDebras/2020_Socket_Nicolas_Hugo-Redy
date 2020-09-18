#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>
#include <iostream>

class Client: public QObject
{
    Q_OBJECT
    private:
        QTcpSocket *m_tcpSocket;
        quint16 m_blockSize;
        QNetworkSession *m_networkSession;

    public:
        Client();
        void send_message(QString texte);

    private slots:
        void lireTexte();
        void afficherErreur( QAbstractSocket::SocketError socketError);

};
#endif // CLIENT_H


