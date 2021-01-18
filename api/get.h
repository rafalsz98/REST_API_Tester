#ifndef GET_H
#define GET_H

#include "restmethod.h"
#include <QVector>

class API_EXPORT Get : public RESTMethod
{
    QVector<QString> parameters{};
public:
    void run();
    void addParameter(const QString& field, const QString& argument);
    void removeParameter(const int& position);
};

#endif // GET_H
