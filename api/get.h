#ifndef GET_H
#define GET_H

#include "restmethod.h"
#include "parameter.h"
#include <QVector>
#include <QList>

class API_EXPORT Get : public RESTMethod
{
    QVector<QString> parameters{};
public:

public slots:
    void run() override;
    void parseParameters(QVariant list) override;
};

#endif // GET_H
