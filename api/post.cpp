#include "post.h"

void Post::run()
{
    if (!finished)
    {
        emit alreadyRunning();
        return;
    }
    finished = false;

    QByteArray fixedParameters = vectorRefactoring(parameters);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, fixedParameters.length());

    qDebug() << request.url();
    networkManager.post(request, fixedParameters);

    if (parameters.length() != 0)
        parameters.clear();
}

void Post::parseParameters(QVariant var)
{
    QList<QVariant> list = var.toList();
    foreach(const QVariant& varParameter, list)
    {
        Parameter parameter = varParameter.value<Parameter>();
        QString data = "\"" + parameter.key + "\":\"" + parameter.value + "\"";
        parameters.push_back(data);
    }
}

QByteArray Post::vectorRefactoring(QVector<QString> params)
{
    QString paramsString = "{";
    QByteArray retVal;
    while(!params.isEmpty())
    {
        paramsString += params.takeFirst();
        if(!params.isEmpty()) paramsString +=',';
    }
    paramsString += "}";
    retVal = paramsString.toUtf8();
    return retVal;
}
