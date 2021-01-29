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

    qDebug()<< request.url();
    networkManager.deleteResource(request);

    setUrl(prevUrl);
}

void Delete::setParameter(const QString& par)
{
    parameter=par;
}
