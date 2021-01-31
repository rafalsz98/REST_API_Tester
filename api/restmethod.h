#ifndef RESTMETHOD_H
#define RESTMETHOD_H

#include "api_global.h"
#include "Parameter.h"

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
    QString parseRawHeadersPairs(const QList<QNetworkReply::RawHeaderPair>& list);
protected:
    QNetworkAccessManager networkManager{};
    QNetworkRequest request{};

    bool finished = true;
    QString url = "";
    QString headers = "";
    QString body = "";
    int statusCode = -1;

public:
    RESTMethod();
    virtual ~RESTMethod();

signals:
    /*!
     * \brief This signal is send every time QNetworkReply has been received completly
     * \param reply
     */
    void replyReady();

    /*!
     * \brief Send every time run function is called and previous call wasn't ended yet
     */
    void alreadyRunning();

public slots:
    /*!
     * \brief Run rest method with given request method
     */
    virtual void run() = 0;

    /*!
     * \brief Parse parameters that are received from UI model
     * \param list
     */
    virtual void parseParameters(QList<Parameter> list) = 0;

    /*!
     * \brief Sets url in request
     * \param url
     * \throws std::invalid_argument
     */
    virtual void setUrl(const QString& url);

    /*!
     * \brief getUrl
     * \return URL String
     */
    virtual QString getUrl() const;

    /*!
     * \brief Gets headers from last reply. Will return empty string if
     * there was no reply, or reply was not yet received
     * \return QString
     */
    virtual QString getHeaders() const;

    /*!
     * \brief Gets body from last reply. Will return empty string if
     * there was no reply, or reply was not yet received
     * \return QString
     */
    virtual QString getBody() const;

    /*!
     * \brief Gets status code from last reply. Will return -1 if
     * there was no reply, or reply was not yet received
     * \return int
     */
    virtual int getStatusCode() const;

    /*!
     * \brief Handles the finished signal from networkManager. Can be overwriten
     * \param reply
     */
    virtual void receiveReply(QNetworkReply* reply);
};

#endif // RESTMETHOD_H
