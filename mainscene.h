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




     //������Ϸ ����������ʱ������
     void playGame();
     //��������
     void updatePosition();
     //��ͼ�¼�
    void paintEvent(QPaintEvent *);

    //��ӵ��˺͵��˳��ֵĺ���
    Enermy enermy[ENERMY_NUM];
    void enermyToScene();
    int recorder;

    Tower tower[TOWER_NUM];

    Map map;


    //��ײ���
    void bomb();

private:
    Ui::MainScene *ui;

};
#endif // MAINSCENE_H
