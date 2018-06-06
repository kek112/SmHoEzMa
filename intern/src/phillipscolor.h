#ifndef PHILLIPSCOLOR_H
#define PHILLIPSCOLOR_H
#include "phillips.h"

class CPhillipsColor : public CPhillips
{
public:
    CPhillipsColor(QObject *parent = 0);
    CPhillipsColor(QObject *parent,
                   bool     _swtichedOn,
                   int      _brightness,
                   int      _saturation,
                   int      _lampnumber,
                   QString  _ip,
                   int      _hueValue);


public:
    void setHueValue(int _huevalue);

private:
    int            m_hueValue;
};

#endif // PHILLIPSCOLOR_H
