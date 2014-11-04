#include "GpsClient.h"
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDebug>

GpsClient::GpsClient(QObject *parent) :
    QObject(parent),
    lat(0),
    lng(0)
{
    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(0);

    if (source)
    {
        source->setUpdateInterval(1000); // 1 second
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
               this, SLOT(positionUpdated(QGeoPositionInfo)));
        source->startUpdates();
    }

    connect(this, SIGNAL(positionChanged()), this, SLOT(getCurrentPosition()));
}

void GpsClient::positionUpdated(const QGeoPositionInfo &info)
{
    QGeoCoordinate coord = info.coordinate();
    lat = coord.latitude();
    lng = coord.longitude();
    if(info.isValid())
    {
        emit positionChanged();
    }

    // qDebug() << "Position updated:" << info;

}

QString GpsClient::getCurrentPosition() const
{
    return QString("(%1, %2)").arg(QString::number(lat), QString::number(lng));
}
