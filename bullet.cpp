#include "bullet.h"

//��һ���ӵ�������
Bullet::Bullet()
{
    m_Bullet.load(":/pics/bullet.png");
    m_x = GAME_WIDTH*0.5-m_Bullet.width()*0.5;
    m_y = GAME_HEIGHT;

    //���ӵ���Ϊ����״̬
    m_Free=true;

    //�����ӵ����ٶ�
    m_Speed=BULLET_SPEED;

    //�����ӵ��ı߿�
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

    //�ñ߿�ʼ�ո����ӵ�
    m_Rect.moveTo(m_x,m_y);

    //����ӵ��ɳ��߿������Ϊ����״̬
    if(m_y<=-m_Rect.height())
    {
        m_Free=true;
    }
}

//�ڶ����ӵ�������
Bullet1::Bullet1()
{
    m_Bullet.load(":/pics/bullet1.png");
    m_Speed=BULLET1_SPEED;
}

