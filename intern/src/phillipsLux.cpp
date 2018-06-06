#include "phillipsLux.h"



CPhillipsLux::CPhillipsLux(QObject *parent)
{

}

CPhillipsLux::CPhillipsLux(QObject *parent,
                           bool _swtichedOn,
                           int _brightness,
                           int _saturation,
                           int _lampnumber,
                           QString _ip):CPhillips(parent,
                                                  _swtichedOn,
                                                  _brightness,
                                                  _saturation,
                                                  _lampnumber,
                                                  _ip)
{

}
