#include "get.h"

#include <QtDebug>

void Get::run()
{
    if (!finished)
    {
        emit alreadyRunning();
        return;
    }
    finished = false;
    QString prevUrl = url;

    if (parameters.length() != 0)
    {
        QString newUrl = url + '?';
        foreach(const QString &param, parameters)
        {
            newUrl.append(param);
            newUrl.append('&');
        }
        newUrl.chop(1);
        setUrl(newUrl);
    }

    qDebug() << request.url();
    networkManager.get(request);

    if (parameters.length() != 0)
    {
        setUrl(prevUrl);
        parameters.clear();
    }
}

void Get::parseParameters(QVariant var)
{
    QList<QVariant> list = var.toList();
    foreach(const QVariant& varParameter, list)
    {
        Parameter parameter = varParameter.value<Parameter>();
        QString parsed = parameter.key + "=" + parameter.value;
        parameters.push_back(parsed);
        qDebug() << parsed;
    }
}
