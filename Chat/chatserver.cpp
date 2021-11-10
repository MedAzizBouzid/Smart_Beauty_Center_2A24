#include "chatserver.h"
#include <QDebug>
#include"chatsocket.h"
#include <QTextStream>
namespace ApexAlliance
{
ChatServer::ChatServer(QObject *parent)
    :QTcpServer(parent)
{

}
 bool ChatServer::startServer(quint16 port)
 {
     return listen(QHostAddress::Any,port);
 }
void ChatServer:: incomingConnection(qintptr handle)
{qDebug()<<"User connected with handle:"<<handle;
    auto socket=new ChatSocket(handle,this);
    mSockets<<socket;

    for(auto i : mSockets)
    {QTextStream T(i);
        T<<"Server: Connected :"<<handle;
        i->flush();

    }


    connect(socket,&ChatSocket::DuReadyRead,[&]( ChatSocket *S)
    {qDebug()<<"DuReadyRead";
        QTextStream T(S);
        auto text=T.readAll();
        for (auto i:mSockets)
        {
            QTextStream K(i);
            K<<text ;
            i->flush();
        }
    });
    connect(socket,&ChatSocket::DuStateChanged,[&](ChatSocket *S,int ST)
        {qDebug()<<"DuStateChanged with handle "<<S->socketDescriptor();
        if (ST==QTcpSocket::UnconnectedState ){
            qDebug()<<"Unconnected State with handle :"<<S->socketDescriptor();
            mSockets.removeOne(S);

            for(auto i: mSockets)
            {QTextStream K(i);
                K<<"Server:le client"<<S->socketDescriptor()<<"est deconnecté..";
                i->flush();
        }
            }

    });
}
}//end apex alliance
