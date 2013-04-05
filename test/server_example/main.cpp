#include <QCoreApplication>

#include <qxmpp/QXmppLogger.h>
#include <qwebdomo/qwserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWServer server("127.0.0.1");
    Q_UNUSED(server);

    return a.exec();
}
