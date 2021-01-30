#ifndef DELETE_H
#define DELETE_H

#include "restmethod.h"

class API_EXPORT Delete : public RESTMethod
{

private:
    QString parameter="";

public:
    Delete();

public slots:
    void run() override;
    void setParameter(const QString&);
};

#endif // DELETE_H
