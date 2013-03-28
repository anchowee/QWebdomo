#ifndef TCPSERVERTHREAD_H
#define TCPSERVERTHREAD_H

#include <QRunnable>
#include <QTcpSocket>

class TcpServerThread : public QRunnable
{
public:
    explicit TcpServerThread(qintptr id);

    void run();
    
signals:

private:
    qintptr _id;
    QTcpSocket *_socket;
    
};

#endif // TCPSERVERTHREAD_H
