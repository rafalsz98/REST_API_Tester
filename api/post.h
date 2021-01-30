#ifndef POST_H
#define POST_H

#include "restmethod.h"
#include <QVector>
#include <QJsonDocument>

class API_EXPORT Post : public RESTMethod
{
    QVector<QJsonDocument> parameters{};
    QByteArray vectorRefactoring(const QVector<QJsonDocument>);
public:

public slots:
    void run() override;
    void addParameter(const QString& field, const QString& argument);
    void removeParameter(const int& position);
};

#endif // POST_H
