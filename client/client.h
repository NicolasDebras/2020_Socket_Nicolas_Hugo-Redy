#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>
#include <iostream>

class client: public QObject
{
    Q_OBJECT
    private:
        QTcpSocket *m_tcpSocket;
        quint16 m_blockSize;
        QNetworkSession *m_networkSession;

    public:
        client();
        void send_message();

    private slots:
        void lireTexte();
        void afficherErreur( QAbstractSocket::SocketError socketError);

};
#endif // CLIENT_H


