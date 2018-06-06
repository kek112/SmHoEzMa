#ifndef MENUBAR_H
#define MENUBAR_H

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
    void ButtonPressed(int index);
    void DeviceButtonPressed();
    void AboutButtonPressed();
    void SleepButtonPressed();

private slots:
    void priavteButtonPressed();

protected:
    void resizeEvent(QResizeEvent* _event);

private:
    QImage*         m_pImage;

    QLabel*         m_pImageLabel;
    QPushButton*    m_pDevicesButton;
    QPushButton*    m_pAboutButton;
    QPushButton*    m_pSleepButton;

    QVBoxLayout*    m_pMainLayout;
};

#endif // MENUBAR_H
