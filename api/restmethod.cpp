#include "restmethod.h"

#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>

RESTMethod::RESTMethod()
{
    QObject::connect(
                &networkManager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(receiveReply(QNetworkReply*))
    );

}

RESTMethod::~RESTMethod()
{

}

void RESTMethod::setUrl(const QString& url)
{
    QUrl qUrl{url};
    if (!qUrl.isValid())
    {
        throw new std::invalid_argument("URL is not valid");
    }
    request.setUrl(qUrl);
    this->url = url;
}

QString RESTMethod::getUrl() const
{
    return url;
}

QString RESTMethod::getHeaders() const
{
    return headers;
}

QString RESTMethod::getBody() const
{
    return body;
}

int RESTMethod::getStatusCode() const
{
    return statusCode;
}

void RESTMethod::receiveReply(QNetworkReply* reply)
{
    // parse reply
    QByteArray json = reply->readAll();
    body = QString(json);
    statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    headers = parseRawHeadersPairs(reply->rawHeaderPairs());

    qDebug() << body << "\n" << statusCode;

    reply->deleteLater();
    finished = true;
    emit replyReady();
}

QString RESTMethod::parseRawHeadersPairs(const QList<QNetworkReply::RawHeaderPair>& list)
{
    return "";
}
