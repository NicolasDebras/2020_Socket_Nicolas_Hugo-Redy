#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>
#include <iostream>

class Client_serv: public QObject
{
    Q_OBJECT
    private:
        QTcpSocket *m_tcpSocket;
        quint16 m_blockSize;
        QNetworkSession *m_networkSession;
        QString recu[2];
        int nb;

    public:
        Client_serv();
        void send_message(QString texte);
        QString get_recu(int i);

    public slots:
        void lireTexte();
        void afficherErreur( QAbstractSocket::SocketError socketError);

};
#endif // CLIENT_H
