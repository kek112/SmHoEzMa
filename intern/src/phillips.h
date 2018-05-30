#ifndef PHILLIPS_H
#define PHILLIPS_H

#include <QObject>
#include <QNetworkReply>

class CPhillips:public QObject
{
    Q_OBJECT
public:
    CPhillips(QObject *parent = 0);
    CPhillips(QObject *parent,
                         bool   _swtichedOn,
                         int    _brightness,
                         int    _saturation,
                         bool   _colorloop,
                         int    _lampnumber,
                         QString _ip);
    ~CPhillips();

    void    switchOn();
    void    switchOff();
    void    callBridge(QJsonDocument _body);
    void    updateAPICall();
private:


    bool    m_switchedOn;
    int     m_brightness;
    int     m_saturation;
    bool    m_colorloop;
    int     m_lampNumber;

    QString  m_ip       = "192.168.178.64";
    QString  m_APICall  = QString("http://")+m_ip+":8000/api/newdeveloper/lights/"+QString::number(m_lampNumber)+"/state";

private slots:
    void reply(QNetworkReply* _networkReply);
};

#endif // PHILLIPS_H
