#include <QCoreApplication>
#include "../Devices/device.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Device dev();

    
    return a.exec();
}
