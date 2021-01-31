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

void Delete::parseParameters(QVariant var)
{
    QList<QVariant> list = var.toList();
    foreach(const QVariant& varParameter, list)
    {
        Parameter parameter = varParameter.value<Parameter>();
        this->parameter = parameter.key;
    }
}
