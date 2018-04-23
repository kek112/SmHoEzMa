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
signals:

public slots:


private:
    QProcess* ping;
};

#endif // PINGMODEL_H
