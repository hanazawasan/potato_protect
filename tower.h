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

    //用于确认鼠标是否点击到相应的防御塔
    bool m_free2;

    //子弹夹
    Bullet m_bullets[BULLET_NUM];
    //计时器，记录子弹发射的间隔
    int m_recorder;

    //塔的价格
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
