#include <QCoreApplication>

#include <qxmpp/QXmppConfiguration.h>

#include <qwebdomo/QWDevice.h>
#include <qwebdomo/QWDeviceConfiguration.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWDeviceConfiguration conf;
    conf.setDomain("picci");
    conf.setStreamSecurityMode(QWDeviceConfiguration::TLSDisabled);
    conf.setUser("appliance");
    conf.setPassword("123");

    QWDevice dev(conf);

    return a.exec();
}
