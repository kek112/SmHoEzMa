#ifndef Philips_H
#define Philips_H

#include <QObject>
#include <QNetworkReply>

class CPhilips:public QObject
{
    Q_OBJECT
public:
    CPhilips(QObject *parent = 0);
    CPhilips(QObject *parent,
                         bool   _swtichedOn,
                         int    _brightness,
                         int    _saturation,
                         int    _lampnumber,
                         QString _ip);
    ~CPhilips();

    void        switchOn();
    void        switchOff();
    void        setBrightness(int _brightness);
    void        setSaturation(int _saturation);
    QString     callBridge(QJsonDocument _body);

private:
    QNetworkAccessManager   manager;
    QNetworkReply*          reply;

    bool    m_switchedOn;
    int     m_brightness;
    int     m_saturation;
    bool    m_colorloop;
    int     m_lampNumber;
    QString m_replyMessage;

    QString  m_ip       = "192.168.178.64";
    QString  m_APICall  = QString("http://")+m_ip+":8000/api/newdeveloper/lights/"+QString::number(m_lampNumber)+"/state";

private:
    void        updateAPICall();

private slots:
    void    waitForReply();

};

#endif // Philips_H
