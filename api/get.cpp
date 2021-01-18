#include "get.h"

#include <QtDebug>

void Get::run()
{
    if (reply != nullptr)
    {
        delete reply;
        reply = nullptr;
    }
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
    reply = networkManager.get(request);

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
