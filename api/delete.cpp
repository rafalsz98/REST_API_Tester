#include "delete.h"

Delete::Delete()
{

}

void Delete::run()
{
    if (!finished)
    {
        emit alreadyRunning();
        return;
    }
    finished = false;

    QString prevUrl = url;

    setUrl(prevUrl +parameter+"/delete/json");

    networkManager.deleteResource(request);
}

void Delete::setParameter(const QString& par)
{
    parameter=par;
}

void Delete::parseParameters(QList<Parameter> list)
{

}
