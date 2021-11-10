#include <QCoreApplication>
#include"chatserver.h"

using namespace ApexAlliance;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ChatServer Server;
    if(!Server.startServer(3333)){
        qDebug()<<"Error:"<<Server.errorString();
        return 1;

    }
    qDebug()<<"Server   started ...";

    return a.exec();
}
