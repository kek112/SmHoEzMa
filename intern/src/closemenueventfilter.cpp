#include "closemenueventfilter.h"

CCloseMenuEventFilter::CCloseMenuEventFilter(QObject *parent) : QObject(parent)
{
    isMenuVisible = false;
}

bool CCloseMenuEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->pos().x() > qApp->activeWindow()->size().width() * 0.7 && isMenuVisible)
        {
            emit closeMenu();
            isMenuVisible = false;
            return true;
        }
    }
    else
    {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
