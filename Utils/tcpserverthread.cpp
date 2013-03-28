#include "tcpserverthread.h"

TcpServerThread::TcpServerThread(qintptr id, QObject *parent) :
    _id(id), QRunnable(parent)
{
}

void TcpServerThread::run()
{
    _socket = new QTcpSocket(this);
    _socket->setSocketDescriptor(_id);
    if(_socket.waitForReadyRead()){
        //TODO: use data
    }
}
