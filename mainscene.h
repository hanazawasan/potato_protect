#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QEvent>
#include<QPainter>
#include<QPen>

#include "mywindow.h"
#include "mybutton.h"


#include<QPixmap>
#include "map.h"
#include "tower.h"
#include<QTimer>
#include<QMediaPlayer>
#include "enermy.h"
#include "enermy1.h"
#include "config.h"
#include<ctime>

#include<vector>
#include<iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

     void initScene();


     QTimer m_Timer;

     void mouseMoveEvent(QMouseEvent *event);

     void mousePressEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);


     //启动游戏 用于启动定时器对象
     void playGame();

     //更新坐标
     void updatePosition();
     //绘图事件
    void paintEvent(QPaintEvent *);


    //添加敌人和敌人出现的函数
    Enermy enermy[ENERMY_NUM];
    Enermy1 enermy1[ENERMY_NUM];
    void enermyToScene();
    int recorder;


    Tower tower[TOWER_NUM];
    Tower1 tower1[TOWER_NUM];


    int money=MONEY_START;
    int blood=HOME_BLOOD;
    int kill=0;

    Map map;


    //敌人与子弹的碰撞检测
    void bomb();

    //敌人与塔的碰撞检测
    void bomb1();

    //生命值检测
    void blood_decrease();

    //敌人是否出现
    void road();
    bool hit[5];

private:
    Ui::MainScene *ui;

};
#endif // MAINSCENE_H
