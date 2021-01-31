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
    this->parameter=list.first().value<Parameter>().key;
}
