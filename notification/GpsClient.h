#ifndef GPSCLIENT_H
#define GPSCLIENT_H

#include <QObject>
#include <QGeoPositionInfo>

class GpsClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString position READ getCurrentPosition NOTIFY positionChanged)
public:
    explicit GpsClient(QObject *parent = 0);  

signals:
    void positionChanged();

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
    QString getCurrentPosition() const;

private:
    double lat;
    double lng;
};

#endif // GPSCLIENT_H
