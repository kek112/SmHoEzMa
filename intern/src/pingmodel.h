#ifndef PINGMODEL_H
#define PINGMODEL_H

#include <QString>
#include <QDebug>
#include <QObject>
#include <QProcess>
#include <QtNetwork>

class PingModel : public QObject
{
    Q_OBJECT
public:
    explicit PingModel(QObject *parent = 0);
    ~PingModel();

    QString CheckForIP();
    bool is_running();
    bool finished();

signals:

public slots:
    void verifyStatus();
    void readResult();

private:
    QProcess *ping;
    bool running;
};

#endif // PINGMODEL_H
