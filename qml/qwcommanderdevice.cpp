#include "qwcommanderdevice.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

QWCommanderDevice::QWCommanderDevice(const QWDeviceConfiguration &configuration, QObject *parent) :
    QWDevice(configuration, parent)
{
    connect(this, SIGNAL(connected()), this, SLOT(getAll()));
}

void QWCommanderDevice::getAll()
{
    QJsonObject content;
    content.insert("subtypes", QJsonArray());
    QJsonObject messageContent;
    messageContent.insert("action", QJsonValue(QString("GET")));
    messageContent.insert("content", content);
    QJsonDocument doc(messageContent);
    emit sendRoomMessage(QString(doc.toJson()));
}

void QWCommanderDevice::changeAppliancesProperties(const QStringList &subtypes, const QHash<QString, QVariant> &values)
{
    composeAndSendRequest("PUT", subtypes, values);
}

void QWCommanderDevice::parseMessage(const QString &senderJid, const QString &type, const QJsonValue &content)
{
    if(!type.contains("NOTIFY")) return;
    if(!content.isArray()) return;

    QJsonArray arr = content.toArray();
    QJsonArray::const_iterator it;

    QList<QQWAppliance *> applianceList;
    for(it = arr.constBegin(); it != arr.constEnd(); ++it){
        QJsonObject el = (*it).toObject();
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
        emit updateAppliances(senderJid, applianceList);
        return;
    }
    emit setAppliances(senderJid, applianceList);
}


void QWCommanderDevice::composeAndSendRequest(const QString &type, const QStringList &subtypes, const QHash<QString, QVariant> &properties)
{
    QJsonObject content;
    //Set message subtypes
    content.insert("subtypes", QJsonArray::fromStringList(subtypes));
    //Set message attributes
    QJsonObject attributes;
    const QStringList attKeys = properties.keys();
    QStringList::const_iterator i;
    for(i = attKeys.constBegin(); i != attKeys.constEnd(); i++){
        attributes.insert(*i, QJsonValue::fromVariant(properties.value(*i)));
    }
    content.insert("attributes", attributes);
    //Add message content
    QJsonObject messageContent;
    messageContent.insert("action", QJsonValue(type));
    messageContent.insert("content", content);
    const QJsonDocument doc(messageContent);
    emit sendRoomMessage(QString(doc.toJson()));
}
