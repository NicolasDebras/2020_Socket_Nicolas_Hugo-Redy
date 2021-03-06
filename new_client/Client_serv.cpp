#include <Client_serv.h>

Client_serv::Client_serv() {

    std::cout << "Application Client" << std::endl;
    m_tcpSocket = new QTcpSocket(this);

    for (int i = 0; i != 100; i++)
        connect( m_tcpSocket, SIGNAL(readyRead()), this,
                 SLOT(lireTexte()));

    connect( m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(afficherErreur(QAbstractSocket::SocketError)));
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config;
    std::cout << "Ouverture session" << std::endl;
    m_networkSession = new QNetworkSession(config, this);
    m_networkSession->open();
    m_blockSize = 0;
    m_tcpSocket->abort();

    m_tcpSocket->connectToHost(
                QHostAddress("127.0.0.1").toString(),53000 );
}
void Client_serv::lireTexte() {

    QDataStream in(m_tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (m_blockSize == 0) {
        if (m_tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> m_blockSize;
    }

    if (m_tcpSocket->bytesAvailable() < m_blockSize)
        return;

    if (nb == 0) {
        in >> recu[nb];
        nb++;
    } else {
        in >> recu[nb];
        nb = 0;
    }
    m_blockSize = 0;
}

void Client_serv::afficherErreur( QAbstractSocket::SocketError socketError) {
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        std::cout << "Le serveur n'a pas ete trouve. Verifiez le parametrage du serveur et du port." << std::endl;
        break;
    case QAbstractSocket::ConnectionRefusedError:
        std::cout << "La communication a ete refusee. Verifiez que le serveur est pret, ainsi que le parametrage du serveur et du port." << std::endl;
        break;
    default:
        std::cout << "L'erreur suivante s'est produite : " <<
                     m_tcpSocket->errorString().toStdString() << std::endl;

    }
}
void Client_serv::send_message(QString texte) {

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << texte;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    m_tcpSocket->write(block);
}
QString Client_serv::get_recu(int i) {

    return recu[i];
}
