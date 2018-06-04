#include "phillips.h"


#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

CPhillips::CPhillips(QObject *parent) : QObject(parent)
{

}
///
/// \brief CPhillips::CPhillips
/// \param parent
/// \param _swtichedOn
/// \param _brightness
/// \param _saturation
/// \param _colorloop
/// \param _lampnumber
///
/// reachable implement to check if bulb is connected to bridge use button in ui for explicit test of the lamp
///
///
CPhillips::CPhillips(QObject *parent,
                     bool   _swtichedOn,
                     int    _brightness,
                     int    _saturation,
                     bool   _colorloop,
                     int    _lampnumber,
                     QString _ip) : QObject(parent)
{
    m_switchedOn=   _swtichedOn;
    m_brightness=   _brightness;
    m_saturation=   _saturation;
    m_colorloop =   _colorloop;
    m_lampNumber=   _lampnumber;
    m_ip=           _ip;

    updateAPICall();

    QJsonObject configurationObject;
    configurationObject.insert("on",        m_switchedOn);
    configurationObject.insert("bri",       m_brightness);
    configurationObject.insert("sat",       m_saturation);
    configurationObject.insert("sat",       m_saturation);
    configurationObject.insert("effect",    m_colorloop ? "colorloop" : "none");
    configurationObject.insert("lampnumber",m_lampNumber);

    QJsonDocument body(configurationObject);

    callBridge(body);
}

CPhillips::~CPhillips()
{

}

void CPhillips::switchOn()
{
    QJsonObject onObject;
    onObject.insert("on","true");
    callBridge(QJsonDocument(onObject));
}
void CPhillips::switchOff()
{
    QJsonObject onObject;
    onObject.insert("on","false");
    callBridge(QJsonDocument(onObject));
}
///
/// \brief CPhillips::callBridge
/// connects to the hue bridge and send commands to the individual lamps
/// create a QJsonDocument which will be accepted by the hue bridge
/// for examples see https://developers.meethue.com/documentation/getting-started
/// thank you for your attention
/// \param _body
///
void CPhillips::callBridge(QJsonDocument _body)
{
    qDebug() << _body.toJson();
    qDebug() << m_APICall;
    QUrl temp = QUrl(m_APICall);
    QNetworkRequest request(temp);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

    QNetworkReply* reply = manager.put(request, _body.toJson());
    QString temp2 = reply->readAll();
    qDebug() <<reply->error();
}

void CPhillips::updateAPICall()
{
    m_APICall  = QString("http://")+m_ip+":8000/api/newdeveloper/lights/"+QString::number(m_lampNumber)+"/state";
}

