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
}

void Post::addParameter(const QString& field, const QString& argument)
{
    QString data = "\"" + field + "\":\"" + argument + "\"";
    parameters.append(data);
}

void Post::removeParameter(const int& position)
{
    parameters.removeAt(position);
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
    retVal += paramsString;
    return retVal;
}
