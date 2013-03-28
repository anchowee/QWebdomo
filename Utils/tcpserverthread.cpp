#include "tcpserverthread.h"

TcpServerThread::TcpServerThread(qintptr id) :
    QRunnable(), _id(id)
{
}

void TcpServerThread::run()
{
    _socket = new QTcpSocket();
    _socket->setSocketDescriptor(_id);
    if(_socket->waitForReadyRead()){
        //TODO: use data
    }
}
