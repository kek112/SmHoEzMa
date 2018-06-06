#ifndef PHILLIPSLUX_H
#define PHILLIPSLUX_H
#include "phillips.h"

class CPhillipsLux : public CPhillips
{
public:
    CPhillipsLux(QObject *parent = 0);
    CPhillipsLux(QObject *parent,
                   bool     _swtichedOn,
                   int      _brightness,
                   int      _saturation,
                   int      _lampnumber,
                   QString  _ip);
};


#endif // PHILLIPSLUX_H
