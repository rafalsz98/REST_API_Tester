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
    }
}

void Get::addParameter(const QString& field, const QString& argument)
{
    QString param = field + '=' + argument;
    parameters.append(param);
}

void Get::removeParameter(const int& position)
{
    parameters.removeAt(position);
}
