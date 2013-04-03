#include <QCoreApplication>

#include <qwebdomo/qwserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWServer server("local");
    Q_UNUSED(server);

    return a.exec();
}
