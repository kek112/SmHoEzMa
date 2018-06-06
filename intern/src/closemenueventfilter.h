#ifndef CLOSEMENUEVENTFILTER_H
#define CLOSEMENUEVENTFILTER_H

#include <QApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QObject>
#include <QWidget>

class CCloseMenuEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit CCloseMenuEventFilter(QObject *parent = nullptr);

signals:
    void closeMenu();
protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    bool isMenuVisible;
};

#endif // CLOSEMENUEVENTFILTER_H
