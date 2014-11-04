#ifndef NETWORKTEST_H
#define NETWORKTEST_H

#include <QNetworkAccessManager>
#include <QNetworkReply>

class NetworkTest : public QObject
{
    Q_OBJECT
public:
    explicit NetworkTest();

    void TestHttps();
    void TestHttp();

private slots:
    void replyFinished(QNetworkReply* reply);
    void networkError(QNetworkReply::NetworkError networkError);
    void sslErrors(QList<QSslError> sslErrors);
private:
    QNetworkAccessManager *manager;
};

#endif // NETWORKTEST_H
