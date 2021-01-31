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
//        throw new std::invalid_argument("URL is not valid");
        qDebug() << "invalid URL given... setting to default...";
        qUrl = "https://www.google.com";
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

    reply->deleteLater();
    finished = true;
    emit replyReady();
}

QString RESTMethod::parseRawHeadersPairs(const QList<QNetworkReply::RawHeaderPair>& list)
{
    QString head;
    foreach(const QNetworkReply::RawHeaderPair& pair, list)
    {
        head+=QString(pair.first) +" "+  QString(pair.second) + '\n';
    }
    return head;
}
