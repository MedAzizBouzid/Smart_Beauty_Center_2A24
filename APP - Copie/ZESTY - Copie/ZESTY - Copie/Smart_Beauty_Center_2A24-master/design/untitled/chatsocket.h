#ifndef CHATSOCKET_H
#define CHATSOCKET_H

#include <QTcpSocket>
namespace ApexAlliance
{
class ChatSocket :public QTcpSocket
{
    Q_OBJECT
public:
    ChatSocket(qintptr handle,QObject *parent =nullptr );

signals:
    void DuReadyRead(ChatSocket *);
    void DuStateChanged (ChatSocket *,int);
};
}//end of apexalliance
#endif // CHATSOCKET_H
