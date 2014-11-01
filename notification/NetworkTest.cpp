#include "NetworkTest.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

NetworkTest::NetworkTest()
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply* reply)), this, SLOT(replyFinished(QNetworkReply* reply)));
}

void NetworkTest::TestHttps()
{

}

void NetworkTest::TestHttp()
{
//    QNetworkRequest request;
//    request.setUrl(QUrl("http://qt-project.org"));
//    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

//    QNetworkReply *reply = manager->get(request);
//    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
//    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
//            this, SLOT(slotError(QNetworkReply::NetworkError)));
//    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
//            this, SLOT(slotSslErrors(QList<QSslError>)));

    manager->get(QNetworkRequest(QUrl("http://qt-project.org")));
}

void NetworkTest::replyFinished(QNetworkReply* reply)
{
    reply->deleteLater();
}
