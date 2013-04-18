#include "QWParser.h"

QWParser::QWParser(QObject *parent) :
    QObject(parent)
{
}

QWParser::ParserType QWParser::type() const
{
    return _type;
}
