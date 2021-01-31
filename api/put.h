#ifndef PUT_H
#define PUT_H

#include "restmethod.h"
#include "parameter.h"
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>


class API_EXPORT Put : public RESTMethod
{
    QJsonObject parameters;
public:

public slots:
    void run() override;
    void parseParameters(QVariant list) override;
};

#endif // PUT_H
