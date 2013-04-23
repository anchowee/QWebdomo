#ifndef QWPARSER_H
#define QWPARSER_H

#include "qwebdomo_global.h"

#include <QObject>
#include <QJsonValue>
#include <QStringList>
#include <QHash>
#include <QVariant>

class QWEBDOMOSHARED_EXPORT QWParser : public QObject
{
    Q_OBJECT
    Q_ENUMS(MessageType)
public:

    enum MessageType {
        GetMessage,
        PutMessage,
        QueryMessage
    };

    explicit QWParser(QObject *parent = 0);
    
signals:
    void sendMessage(const QString &bareJid, const QString &message);
    void doPut(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void doGet(const QStringList &subtypes, const QHash<QString, QVariant> &commands);
    void notify(const QString &message);
    
public slots:
    virtual void parse(const QString &bareJid, MessageType type, const QJsonValue &content) = 0;
};

#endif // QWPARSER_H
