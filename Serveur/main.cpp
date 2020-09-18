#include <QCoreApplication>
#include <serveur.h>

int main (int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    serveur Serveur;

    //std::cout << "sdfdsfdsfds\n" <<  std::endl;
    return a.exec();
}
