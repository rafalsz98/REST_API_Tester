#ifndef POST_H
#define POST_H

#include "restmethod.h"
#include "parameter.h"
#include <QVector>
#include <QVariant>

class API_EXPORT Post : public RESTMethod
{
    QVector<QString> parameters{};
    QByteArray vectorRefactoring(const QVector<QString>);
public:

public slots:
    void run() override;
    void parseParameters(QVariant list) override;
};

#endif // POST_H
