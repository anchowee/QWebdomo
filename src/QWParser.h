#ifndef QWPARSER_H
#define QWPARSER_H

#include <QObject>

class QWParser : public QObject
{
    Q_OBJECT
    Q_ENUMS(ParserType)
public:

    enum ParserType {
        NullParser = 0,
        GetParser,
        PutParser,
        QueryParser
    };

    explicit QWParser(QObject *parent = 0);

    ParserType type() const;
    
signals:
    
public slots:

protected:
    const ParserType _type = NullParser;
};

#endif // QWPARSER_H
