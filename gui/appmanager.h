#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>

class AppManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentlyActiveTab READ currentlyActiveTab WRITE setCurrentlyActiveTab NOTIFY currentlyActiveTabChanged)
    Q_PROPERTY(int statusCode READ statusCode WRITE setStatusCode NOTIFY statusCodeChanged)
    Q_PROPERTY(QString headers READ headers WRITE setHeaders NOTIFY headersChanged)
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)

public:
    explicit AppManager(QObject *parent = nullptr) : QObject(parent) {}

    QString currentlyActiveTab() {
        return m_currentlyActiveTab;
    }
    void setCurrentlyActiveTab(QString val) {
        m_currentlyActiveTab = val;
    }

    int statusCode() {
        return m_statusCode;
    }
    void setStatusCode(int val) {
        m_statusCode = val;
    }

    QString headers() {
        return m_headers;
    }
    void setHeaders(QString val) {
        m_headers = val;
    }

    QString body() {
        return m_body;
    }
    void setBody(QString val) {
        m_body = val;
    }

signals:
    void currentlyActiveTabChanged();
    void statusCodeChanged();
    void headersChanged();
    void bodyChanged();

private:
    QString m_currentlyActiveTab = "GET";
    int m_statusCode = 0;
    QString m_headers = "Run rest method to get headers";
    QString m_body = "Run rest method to get body";
};

#endif // APPMANAGER_H
