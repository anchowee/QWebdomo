#ifndef QWAPPLIANCE_H
#define QWAPPLIANCE_H

#include"qwebdomo_global.h"

#include <QHash>
#include <QStringList>
#include <QSharedDataPointer>
#include <QVariant>

class QWAppliancePrivate;

class QWEBDOMOSHARED_EXPORT QWAppliance
{
public:
    QWAppliance();
    QWAppliance(const QWAppliance &other);
    ~QWAppliance();

    void setName(const QString &name);
    QString name() const;

    void setSubtypes(const QStringList &subtypes);
    QStringList subtypes() const;
    void addSubtype(const QString &subtype);

    void setAttributes(const QHash<QString, QVariant> &attributes);
    QHash<QString, QVariant> attributes() const;
    void setAttribute(const QString &name, const QVariant &value);
    QVariant getAttribute(const QString &name) const;

private:
    QSharedDataPointer<QWAppliancePrivate> d;
};

#endif // QWAPPLIANCE_H
