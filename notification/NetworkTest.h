#ifndef NETWORKTEST_H
#define NETWORKTEST_H

#include <QNetworkAccessManager>

class NetworkTest : public QObject
{
public:
    NetworkTest();

    void TestHttps();
    void TestHttp();

signals:
    void finished();

private slots:
    void replyFinished(QNetworkReply* reply);
private:
    QNetworkAccessManager *manager;
};

#endif // NETWORKTEST_H
