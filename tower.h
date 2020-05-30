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

    //用于检测防御塔是否被鼠标移动
    bool m_free;

    //用于固定防御塔被放好后的位置：
    bool m_free1;

    //子弹夹
    Bullet m_bullets[BULLET_NUM];
    //计时器，记录子弹发射的间隔
    int m_recorder;

};

#endif // TOWER_H
