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
    if (parameters.length() != 0)
    {
        QString newUrl = url + '?';
        foreach(const QString &param, parameters)
        {
            newUrl.append(param);
            newUrl.append('&');
        }
        newUrl.chop(1);
        QUrl qUrl{newUrl};
        request.setUrl(qUrl);
    }

    qDebug() << request.url();
    networkManager.get(request);

    if (parameters.length() != 0)
    {
        QUrl qUrl{url};
        request.setUrl(qUrl);
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
