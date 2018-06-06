#ifndef DEVICELISTVIEW_H
#define DEVICELISTVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolBox>
#include <QWidget>

class CDeviceListView : public QWidget
{
    Q_OBJECT
public:
    explicit CDeviceListView(QWidget *parent = nullptr);

signals:

public slots:

private:
    QGridLayout*    m_pMainLayout;

    QToolBox*       m_pDeviceToolBox;
    QPushButton*    m_pAddDeviceButton;
    QPushButton*    m_pRemoveDeviceButton;
};

#endif // DEVICELISTVIEW_H
