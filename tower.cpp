#include "tower.h"

Tower::Tower()
{
   m_Tower.load(":/pics/tower1.png");
   m_x=0;
   m_y=0;

   m_Rect.setWidth(m_Tower.width());
   m_Rect.setHeight(m_Tower.height());
   m_Rect.moveTo(m_x,m_y);
   //子弹的计时器
   m_recorder=0;

   //防御塔是否可用鼠标操作
   m_free=true;

   //防御塔是否安置好:
   m_free1=false;
}

 void Tower::setPosition(int x,int y)
 {
     m_x=x;
     m_y=y;
     m_Rect.moveTo(m_x,m_y);
 }

void Tower::shoot()
{
    m_recorder++;
    //设置了一个子弹发射的时间间隔
    if(m_recorder<BULLET_INTERVAL)
    {
        return;
    }
    m_recorder=0;

    for(int i=0;i<BULLET_NUM;i++)
    {   //如果子弹为闲置，就让它发射出来
        if(m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free=false;
            m_bullets[i].m_x=m_x+m_Tower.width()*0.5-m_bullets[i].m_Bullet.width()*0.5;
            m_bullets[i].m_y=m_y;
            break;
        }
    }
}
