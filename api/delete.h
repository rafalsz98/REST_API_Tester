#ifndef DELETE_H
#define DELETE_H

#include "restmethod.h"

class API_EXPORT Delete : public RESTMethod
{

private:
    QVector<QString> parameters{};

public:
    Delete();

public slots:
    void run() override;
    void addParameter(const QString& parameter);
    void removeParameter(const QString& parameter);
};

#endif // DELETE_H
