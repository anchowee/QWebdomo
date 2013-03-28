#ifndef TCPSERVERTHREAD_H
#define TCPSERVERTHREAD_H

#include <QRunnable>
#include <QTcpSocket>

class TcpServerThread : public QRunnable
{
    Q_OBJECT
public:
    explicit TcpServerThread(qintptr id, QObject *parent = 0);

    void run();
    
signals:

private:
    qintptr _id;
    QTcpSocket *_socket;
    
};

#endif // TCPSERVERTHREAD_H
