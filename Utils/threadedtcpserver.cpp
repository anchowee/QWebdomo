#include "threadedtcpserver.h"
#include "tcpserverthread.h"

#include <QThreadPool>

ThreadedTcpServer::ThreadedTcpServer(QObject *parent) :
    QTcpServer(parent)
{
}

void ThreadedTcpServer::incomingConnection(qintptr handle)
{
    TcpServerThread *consumer = new TcpServerThread(handle);
    //TODO: connect signals and slot
    QThreadPool::globalInstance()->start(consumer);
}
