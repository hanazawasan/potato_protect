#include "bullet.h"

//第一类子弹的设置
Bullet::Bullet()
{
    m_Bullet.load(":/pics/bullet.png");
    m_x = GAME_WIDTH*0.5-m_Bullet.width()*0.5;
    m_y = GAME_HEIGHT;

    //把子弹定为闲置状态
    m_Free=true;

    //定义子弹的速度
    m_Speed=BULLET_SPEED;

    //设置子弹的边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_x,m_y);
}
void Bullet::updatePosition()
{
    if(m_Free)
    {
        return;
    }
    m_y-=m_Speed;

    //让边框始终跟着子弹
    m_Rect.moveTo(m_x,m_y);

    //如果子弹飞出边框，让其变为闲置状态
    if(m_y<=-m_Rect.height())
    {
        m_Free=true;
    }
}

//第二类子弹的设置
Bullet1::Bullet1()
{
    m_Bullet.load(":/pics/bullet1.png");
    m_Speed=BULLET1_SPEED;
}

