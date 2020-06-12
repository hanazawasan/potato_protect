#include "tower.h"
//��һ��������������
Tower::Tower()
{
   m_Tower.load(":/pics/tower1.png");
   m_x=1000;
   m_y=0;

   m_Rect.setWidth(m_Tower.width());
   m_Rect.setHeight(m_Tower.height());
   m_Rect.moveTo(m_x,m_y);
   //�ӵ��ļ�ʱ��
   m_recorder=0;

   //�������Ƿ����������
   m_free=true;

   //�������Ƿ��ú�:
   m_free1=false;

   //����Ƿ�㵽��Ӧ������
   m_free2=false;

   m_price=TOWER_PRICE;

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
    //������һ���ӵ������ʱ����
    if(m_recorder<BULLET_INTERVAL)
    {
        return;
    }
    m_recorder=0;
    int m=m_x/200;
    if(m_free==false && hit[m]==true)
    {for(int i=0;i<BULLET_NUM;i++)
    {   //����ӵ�Ϊ���ã��������������
        if(m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free=false;
            m_bullets[i].m_x=m_x+m_Tower.width()*0.5-m_bullets[i].m_Bullet.width()*0.5;
            m_bullets[i].m_y=m_y;
            break;
        }
    }
    }
}

//�ڶ���������������
Tower1::Tower1()
{
    m_Tower.load(":/pics/tower.png");
    m_y=200;
    m_price=TOWER1_PRICE;
}

void Tower1::shoot1()
{
    m_recorder1=m_recorder1+2;
    if(m_recorder1<BULLET1_INTERVAL)
    {return;}
    m_recorder1=0;
    int m=m_x/200;
    if(m_free==false && hit[m]==true)
    {for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_bullets1[i].m_Free)
        {
            m_bullets1[i].m_Free=false;
            m_bullets1[i].m_x=m_x+m_Tower.width()*0.5-m_bullets1[i].m_Bullet.width()*0.5;
            m_bullets1[i].m_y=m_y;
            break;
        }
    }
    }
}

void Tower1::shoot2()
{
    m_recorder1=m_recorder1+2;
    if(m_recorder1<BULLET1_INTERVAL)
    {return;}
    m_recorder1=0;
    int m=m_x/200;
    if(m_free==false && hit[m]==true)
    {for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_bullets2[i].m_Free)
        {
            m_bullets2[i].m_Free=false;
            m_bullets2[i].m_x=m_x+m_Tower.width()*0.5-m_bullets1[i].m_Bullet.width()*0.5-200;
            m_bullets2[i].m_y=m_y;
            break;
        }
    }
    }
}

void Tower1::shoot3()
{
    m_recorder1=m_recorder1+2;
    if(m_recorder1<BULLET1_INTERVAL)
    {return;}
    m_recorder1=0;
    int m=m_x/200;
    if(m_free==false && hit[m]==true)
    {for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_bullets3[i].m_Free)
        {
            m_bullets3[i].m_Free=false;
            m_bullets3[i].m_x=m_x+m_Tower.width()*0.5-m_bullets1[i].m_Bullet.width()*0.5+200;
            m_bullets3[i].m_y=m_y;
            break;
        }
    }
    }
}


