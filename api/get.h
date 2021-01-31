#ifndef GET_H
#define GET_H

#include "restmethod.h"
#include "Parameter.h"
#include <QVector>
#include <QList>

class API_EXPORT Get : public RESTMethod
{
    QVector<QString> parameters{};
public:

public slots:
    void run() override;
    void parseParameters(QList<Parameter> list);
};

#endif // GET_H
