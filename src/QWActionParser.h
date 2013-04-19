#ifndef QWACTIONPARSER_H
#define QWACTIONPARSER_H

#include "qwebdomo_global.h"
#include "QWParser.h"

class QWEBDOMOSHARED_EXPORT QWActionParser : public QWParser
{
    Q_OBJECT
public:
    explicit QWActionParser(QObject *parent = 0);

public slots:
    void parse(const QString &bareJid, MessageType type, const QJsonValue &content);
};

#endif // QWACTIONPARSER_H
