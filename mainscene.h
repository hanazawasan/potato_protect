#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QEvent>
#include<QPainter>
#include<QPixmap>
#include "map.h"
#include "tower.h"
#include<QTimer>
#include<QMediaPlayer>
#include "enermy.h"
#include "config.h"

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




     //启动游戏 用于启动定时器对象
     void playGame();
     //更新坐标
     void updatePosition();
     //绘图事件
    void paintEvent(QPaintEvent *);

    //添加敌人和敌人出现的函数
    Enermy enermy[ENERMY_NUM];
    void enermyToScene();
    int recorder;

    Tower tower[TOWER_NUM];

    Map map;


    //碰撞检测
    void bomb();

private:
    Ui::MainScene *ui;

};
#endif // MAINSCENE_H
