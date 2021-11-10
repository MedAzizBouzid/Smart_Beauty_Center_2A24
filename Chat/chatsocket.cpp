#include "chatsocket.h"
namespace ApexAlliance
{
ChatSocket::ChatSocket(qintptr handle,QObject *parent )
    :QTcpSocket(parent)
{
setSocketDescriptor(handle);
connect(this,&ChatSocket::readyRead,[&](){
    emit DuReadyRead(this);
});
connect (this,&ChatSocket::stateChanged,[&](int S )
{
   emit DuStateChanged(this,S);
});
}
}//end namespace apex alliance
