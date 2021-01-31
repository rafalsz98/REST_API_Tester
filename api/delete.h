#ifndef DELETE_H
#define DELETE_H

#include "restmethod.h"
#include "parameter.h"

class API_EXPORT Delete : public RESTMethod
{

private:
    QString parameter="";

public:
    Delete();

public slots:
    void run() override;
    void parseParameters(QVariant list) override;
};

#endif // DELETE_H
