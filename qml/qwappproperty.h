#ifndef QWAPPPROPERTY_H
#define QWAPPPROPERTY_H

#include <QObject>

class QWAppProperty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit QWAppProperty(QObject *parent = 0);

    //name
    QString name() const;
    void setName(const QString &name);

    //value
    QVariant value() const;
    void setValue(const QVariant &value);

private:
    QString _name;
    QVariant *_value;
    
};

#endif // QWAPPPROPERTY_H
