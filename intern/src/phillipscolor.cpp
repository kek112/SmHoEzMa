#include "phillipscolor.h"
#include "phillips.h"
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

CPhillipsColor::CPhillipsColor(QObject *parent)
{

}

CPhillipsColor::CPhillipsColor(QObject *parent,
                               bool _swtichedOn,
                               int _brightness,
                               int _saturation,
                               int _lampnumber,
                               QString _ip,
                               int _hueValue) : CPhillips
                                                ( parent,
                                                 _swtichedOn,
                                                 _brightness,
                                                 _saturation,
                                                 _lampnumber,
                                                 _ip)
{
    m_hueValue=_hueValue;
}

void CPhillipsColor::setHueValue(int _huevalue)
{
    QJsonObject onObject;
    onObject.insert("hue",_huevalue);
    CPhillips::callBridge(QJsonDocument(onObject));
}


