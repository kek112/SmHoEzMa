#include "humiditysensor.h"



CHumiditySensor::CHumiditySensor(int _sensorNumber, QString _ip)
{

}

int CHumiditySensor::getHumidity()
{
    QUrl temp = QUrl(m_APICall);
    QNetworkRequest request(temp);

    reply = manager.put(request, _body.toJson());

    connect(reply , SIGNAL(readyRead()) , this , SLOT(waitForReply()));

    return m_replyMessage;
}

void CHumiditySensor::updateAPICall()
{

}

void CPhillips::waitForReply()
{
    m_replyMessage = reply->readAll();
}

void CPhillips::updateAPICall()
{
    m_APICall  = QString("http://")+m_ip+":8000/api/newdeveloper/lights/"+QString::number(m_lampNumber)+"/state";
}


