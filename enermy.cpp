#include "enermy.h"

Enermy::Enermy()
{
    m_enermy.load(":/pics/enermy.png");
    m_x=0;
    m_y=0;
    m_speed=ENERMY_SPEED;
    m_Free=true;
    m_Rect.setWidth(m_enermy.width());
    m_Rect.setHeight(m_enermy.height());
    m_Rect.moveTo(m_x,m_y);

    m_blood=ENERMY_BLOOD;
}

void Enermy::updatePosition()
{
    if(m_Free)
    {
        return;
    }
    m_y+=m_speed;
    m_Rect.moveTo(m_x,m_y);
    if(m_y>=GAME_HEIGHT)
    {
        m_Free=true;
    }
}
