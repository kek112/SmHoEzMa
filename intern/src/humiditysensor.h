#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include <QObject>
#include <QNetworkReply>

class CHumiditySensor
{
public:
    CHumiditySensor(int    _sensorNumber,
                    QString _ip);

public:
    int getHumidity();

private:
    int                     m_sensorNumber;
    QString                 m_replyMessage;
    QNetworkAccessManager   manager;
    QNetworkReply*          reply;


    QString  m_ip       = "192.168.178.64";
    QString  m_APICall  = QString("http://")+m_ip+":8080/api/Humidity/"+QString::number(m_lampNumber);

private:
    void        updateAPICall();

};

#endif // HUMIDITYSENSOR_H
