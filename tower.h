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

    //�ӵ���
    Bullet m_bullets[BULLET_NUM];
    //��ʱ������¼�ӵ�����ļ��
    int m_recorder;

};

#endif // TOWER_H
