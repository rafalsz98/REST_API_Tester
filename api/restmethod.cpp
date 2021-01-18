#include "restmethod.h"

#include <QObject>

RESTMethod::RESTMethod()
{
    reply = nullptr;

    QObject::connect(
                &networkManager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(receiveReply(QNetworkReply*))
    );

}

RESTMethod::~RESTMethod()
{
    delete reply;
}



void RESTMethod::setUrl(QString url)
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

QNetworkReply* RESTMethod::getLastReply() const
{
    return reply;
}

void RESTMethod::receiveReply(QNetworkReply* reply)
{
    emit replyReady(reply);
}
