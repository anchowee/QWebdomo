#include "qwcommanderdevice.h"

#include <QJsonObject>
#include <QJsonArray>

QWCommanderDevice::QWCommanderDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QWDevice(configuration, parent)
{
}

void QWCommanderDevice::inspectAppliances()
{
    //TODO: send a GET command to every appliance
}

void QWCommanderDevice::parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content)
{
    if(!type.contains("NOTIFY")) return;
    if(!content.isArray()) return;

    QJsonArray arr = content.toArray();
    QJsonArray::const_iterator it;

    QList<QQWAppliance *> applianceList;
    for(it = arr.constBegin(); it != arr.constEnd(); ++it){
        QJsonObject el = QJsonValue(*it).toObject();
        QQWAppliance *app = new QQWAppliance;

        app->setName(el.value("name").toString());

        QJsonArray st = el.value("subtypes").toArray();
        for(int i = 0; i < st.size(); i++){
            app->addSubtype(st.at(i).toString());
        }

        QJsonObject cmds = el.value("commands").toObject();
        foreach(QString key, cmds.keys()){
            app->addProperty(key, cmds.value(key).toVariant());
        }

        applianceList.append(app);
    }

    if(type == "NOTIFY_PUT"){
        emit updateAppliances(applianceList);
        return;
    }
    emit setAppliances(applianceList);
}
