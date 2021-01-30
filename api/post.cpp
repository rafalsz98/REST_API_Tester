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
    QString data = "{\"" + field + "\":\"" + argument + "\"}";
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    parameters.append(doc);
}

void Post::removeParameter(const int& position)
{
    parameters.removeAt(position);
}

QByteArray Post::vectorRefactoring(QVector<QJsonDocument> params)
{
    QByteArray retVal;
    while(!params.isEmpty())
    {
        retVal += params.takeFirst().toJson();
        if(!params.isEmpty()) retVal +=',';
    }
    return retVal;
}
