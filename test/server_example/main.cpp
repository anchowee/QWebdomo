#include <QCoreApplication>

#include <qwebdomo/qwserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString domain("local");
    QWServer *server= new QWServer(domain);

    return a.exec();
}
