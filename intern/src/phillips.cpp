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

}
void CPhillips::switchOff()
{
    QJsonObject onObject;
    onObject.insert("on","false");
    callBridge(QJsonDocument(onObject));
}
void CPhillips::callBridge(QJsonDocument _body)
{
    QNetworkAccessManager manager;

    QNetworkRequest request(QUrl(m_APICall));

    QNetworkReply* reply = manager.put(request, _body.toJson());
    /*
    QNetworkAccessManager *manager = new QNetworkAccessManager::PutOperation(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl(m_APICall);*/
}

void CPhillips::reply(QNetworkReply *_networkReply)
{

}
