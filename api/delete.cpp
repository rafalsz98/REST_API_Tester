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

    foreach(const QString &param, parameters)
    {
        QString newUrl = prevUrl +param+"/delete/json";
        setUrl(newUrl);

        qDebug()<< request.url();
        networkManager.deleteResource(request);
    }

    setUrl(prevUrl);
}

void Delete::addParameter(const QString& parameter)
{
    parameters.append(parameter);
}

void Delete::removeParameter(const QString &parameter)
{
    parameters.removeOne(parameter);
}

