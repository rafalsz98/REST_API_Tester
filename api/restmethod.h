#ifndef RESTMETHOD_H
#define RESTMETHOD_H

#include "api_global.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QString>

/*!
 * \brief Abstract class for every REST API method
 */
class API_EXPORT RESTMethod : public QObject
{
    Q_OBJECT

protected:
    QNetworkAccessManager networkManager{};
    QNetworkReply* reply;
    QNetworkRequest request{};

    QString url;

public:
    RESTMethod();
    virtual ~RESTMethod();

    /*!
     * \brief Run rest method with given request method
     *
     * Important: While implementing you need to perform nullptr check on
     * QNetworkReply*. If it's not nullptr, use delete
     */
    virtual void run() = 0;

    /*!
     * \brief Sets url in request
     * \param url
     * \throws std::invalid_argument
     */
    void setUrl(const QString& url);
    /*!
     * \brief getUrl
     * \return URL String
     */
    QString getUrl() const;

    QNetworkReply* getLastReply() const;

signals:
    /*!
     * \brief This signal is send every time QNetworkReply has been received completly
     * \param reply
     */
    void replyReady(QNetworkReply* reply);
public slots:
    /*!
     * \brief Handles the finished signal from networkManager
     * \param reply
     */
    void receiveReply(QNetworkReply* reply);
};

#endif // RESTMETHOD_H
