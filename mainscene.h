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


     //������Ϸ ����������ʱ������
     void playGame();

     //��������
     void updatePosition();
     //��ͼ�¼�
    void paintEvent(QPaintEvent *);


    //��ӵ��˺͵��˳��ֵĺ���
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


    //�������ӵ�����ײ���
    void bomb();

    //������������ײ���
    void bomb1();

    //����ֵ���
    void blood_decrease();

    //�����Ƿ����
    void road();
    bool hit[5];

private:
    Ui::MainScene *ui;

};
#endif // MAINSCENE_H
