#ifndef ENERMY_H
#define ENERMY_H

#include<QPixmap>
#include "config.h"

class Enermy
{
public:
    Enermy();

    void updatePosition();
public:
    QPixmap m_enermy;

    int m_x;
    int m_y;

    bool m_Free;

    QRect m_Rect;

    int m_speed;

    int m_blood;

};

#endif // ENERMY_H
