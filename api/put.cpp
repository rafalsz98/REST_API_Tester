#include "put.h"


void Put::run()
{
    if (!finished)
    {
        emit alreadyRunning();
        return;
    }
    finished = false;

    if(parameters.isEmpty()){
       qDebug() << "Parameters list is empty!";
        return;
    }
    QJsonDocument doc(parameters);
    QByteArray data = doc.toJson();
    //qDebug() << data;
    networkManager.put(request, data);
}

void Put::parseParameters(QVariant var)
{
    QList<QVariant> list = var.toList();
    foreach(const QVariant& varParameter, list)
    {
        Parameter parameter = varParameter.value<Parameter>();
        parameters[parameter.key]=parameter.value;
    }
}
