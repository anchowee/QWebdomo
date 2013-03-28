#ifndef THREADEDTCPSERVER_H
#define THREADEDTCPSERVER_H

#include <QTcpServer>

class ThreadedTcpServer: public QTcpServer
{
    
public:
    ThreadedTcpServer(QObject *parent = 0);

protected:
    void incomingConnection(qintptr handle);
};

#endif // THREADEDTCPSERVER_H
