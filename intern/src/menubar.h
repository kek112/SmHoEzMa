#ifndef MENUBAR_H
#define MENUBAR_H

#include <QButtonGroup>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QWidget>

class CMenuBar : public QWidget
{
    Q_OBJECT
public:
    explicit CMenuBar(QWidget *parent = nullptr);

signals:
    void DeviceButtonPressed();
    void AboutButtonPressed();
    void SleepButtonPressed();

private slots:
    void priavteButtonPressed(QAbstractButton *_pressedButton);

protected:
    void resizeEvent(QResizeEvent* _event);

private:
    QPixmap          m_Image;

    QLabel*         m_pImageLabel;
    QPushButton*    m_pDevicesButton;
    QPushButton*    m_pAboutButton;
    QPushButton*    m_pSleepButton;

    QVBoxLayout*    m_pMainLayout;
};

#endif // MENUBAR_H
