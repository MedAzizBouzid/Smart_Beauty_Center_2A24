#ifndef CHATSERVER_H
#define CHATSERVER_H

#include<QTcpServer>
namespace ApexAlliance
{
class ChatSocket;

class ChatServer: public QTcpServer
{
public:
    ChatServer(QObject* parent=nullptr);
    bool startServer(quint16 port);

private :
QList <ChatSocket *> mSockets;
protected:
void incomingConnection(qintptr handle);

};
   } //end of Apexalliance
#endif // CHATSERVER_H
