#ifndef TOWER_H
#define TOWER_H


#include<QPixmap>
#include "config.h"
#include "bullet.h"

class Tower
{
public:
    Tower();

    void shoot();
    void setPosition(int x,int y);
public:
    QPixmap m_Tower;

    int m_x;
    int m_y;

    QRect  m_Rect;

    //���ڼ��������Ƿ�����ƶ�
    bool m_free;

    //���ڹ̶����������źú��λ�ã�
    bool m_free1;

    //����ȷ������Ƿ�������Ӧ�ķ�����
    bool m_free2;

    //�ӵ���
    Bullet m_bullets[BULLET_NUM];
    //��ʱ������¼�ӵ�����ļ��
    int m_recorder;

    //���ļ۸�
    double m_price;

    bool hit[5];

};

class Tower1:public Tower
{
public:
    Tower1();
    void shoot1();
    void shoot2();
    void shoot3();

    Bullet1 m_bullets1[BULLET_NUM];
    Bullet1 m_bullets2[BULLET_NUM];
    Bullet1 m_bullets3[BULLET_NUM];

    int m_recorder1;
};

#endif // TOWER_H
