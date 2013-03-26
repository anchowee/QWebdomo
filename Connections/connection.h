#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>

class Connection : public QObject
{
    Q_OBJECT
public:
    explicit Connection(QObject *parent = 0);

    void recive();
    void send();
    
signals:
    void queryRecived();
    void responseRecived();
    
public slots:
    
};

#endif // CONNECTION_H
