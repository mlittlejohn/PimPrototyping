#include "NetworkTest.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

NetworkTest::NetworkTest()
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    connect(manager, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkError(QNetworkReply::NetworkError)));
    connect(manager, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(slotSslErrors(QList<QSslError>)));
}

void NetworkTest::TestHttps()
{
    manager->get(QNetworkRequest(QUrl("https://androidquery.appspot.com/api/market?app=com.ridecharge.android.taximagic")));
}

void NetworkTest::TestHttp()
{
//    QNetworkRequest request;
//    request.setUrl(QUrl("http://qt-project.org"));
//    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

//    QNetworkReply *reply = manager->get(request);
//    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
//    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
//            this, SLOT(slotSslErrors(QList<QSslError>)));

    manager->get(QNetworkRequest(QUrl("http://qt-project.org")));
}

void NetworkTest::replyFinished(QNetworkReply* reply)
{
    qDebug() << "SIZE: " << reply->bytesAvailable();
    qDebug() << "BODY: " << QString(reply->readAll());
    reply->deleteLater();
}


void NetworkTest::networkError(QNetworkReply::NetworkError networkError)
{
    qDebug() << "ERROR: " << networkError;
}

void NetworkTest::sslErrors(QList<QSslError> sslErrors)
{
    for(int i = 0; i < sslErrors.size(); ++i)
    {
        qDebug() << "ERROR: " << sslErrors[i];
    }
}
