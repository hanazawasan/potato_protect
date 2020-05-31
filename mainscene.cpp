#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
}

MainScene::~MainScene()
{
    delete ui;
}
void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    playGame();



    recorder=0;

    //背景音乐的播放
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/backgroudmusic.mp3"));
    player->setVolume(30);
    player->play();
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(map.m_map_x,map.m_map_y,map.m_map);
    for(int i=0;i<TOWER_NUM;i++)
    {painter.drawPixmap(tower[i].m_x,tower[i].m_y,tower[i].m_Tower);}



    for(int j=0;j<TOWER_NUM;j++)
    {for(int i = 0 ;i < BULLET_NUM;i++)
    { //如果子弹状态为非空闲，计算发射位置
        if(tower[j].m_x>=map.m_map_x)
        {if(!tower[j].m_bullets[i].m_Free)
        {
         painter.drawPixmap(tower[j].m_bullets[i].m_x,tower[j].m_bullets[i].m_y,tower[j].m_bullets[i].m_Bullet );
        }
        }
    }
    }


    for(int i=0;i<ENERMY_NUM;i++)
    {
        if(!enermy[i].m_Free)
        {
            painter.drawPixmap(enermy[i].m_x,enermy[i].m_y,enermy[i].m_enermy);
        }
    }
}

void MainScene::playGame()
{
    m_Timer.start();
    connect(&m_Timer,&QTimer::timeout,[=](){
        enermyToScene();
        updatePosition();
        update();
        bomb();
    });
}

void MainScene::updatePosition()
{

    for(int i=0;i<TOWER_NUM;i++)
    {
        tower[i].shoot();
    }

    for(int j=0;j<TOWER_NUM;j++)
    //更新子弹的坐标
    {for(int i = 0 ;i < BULLET_NUM;i++)
    { //如果子弹状态为非空闲，计算发射位置
        if(!tower[j].m_bullets[i].m_Free)
        { tower[j].m_bullets[i].updatePosition(); }
    }
    }

    //更新敌人的坐标
    for(int i=0;i<ENERMY_NUM;i++)
    {
        if(enermy[i].m_Free==false)
        {
            enermy[i].updatePosition();
        }
    }
}

void MainScene::enermyToScene()
{
    recorder++;
    if(recorder<ENERMY_INTERVAL)
    {
        return;
    }
    recorder=0;
    for(int i=0;i<ENERMY_NUM;i++)
    {
        if(enermy[i].m_Free)
        {
            enermy[i].m_Free=false;
            enermy[i].m_x=GAME_WIDTH*0.5-enermy[i].m_enermy.width()*0.5;
            enermy[i].m_y=-enermy[i].m_enermy.height();
            break;
        }
    }
}

void MainScene::bomb()
{
        for(int k=0;k<TOWER_NUM;k++)
        { for(int i=0;i<ENERMY_NUM;i++)
        {
        if(enermy[i].m_Free)
        {continue;}

        {for(int j=0;j<BULLET_NUM;j++)
        {
            if(tower[k].m_bullets[j].m_Free)
            {continue;}
            if(enermy[i].m_Rect.intersects(tower[k].m_bullets[j].m_Rect))
            {
            if(enermy[i].m_blood==0)
            {enermy[i].m_Free=true;enermy[i].m_blood=ENERMY_BLOOD;}
            else enermy[i].m_blood--;
            tower[k].m_bullets[j].m_Free = true;
            }
        }
    }
            }
        }

}

int s=0;
void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    if(s==0)
    {
        if(tower[s].m_free)
        {
           int x=event->x()-tower[s].m_Rect.width()*0.5;
           int y=event->y()-tower[s].m_Rect.height()*0.5;
           tower[s].setPosition(x,y);
        }
        if(tower[s].m_x>=map.m_map_x && tower[s].m_free==true)
        {
            tower[s].m_free=false;
            int x=GAME_WIDTH*0.5-tower[s].m_Rect.width()*0.5;
            int k=event->y();
            k=k/150;
            int y=150*k;
            tower[s].setPosition(x,y);
            s++;
        }
    }
    if(s>=TOWER_NUM)
    {return;}
    if(tower[s-1].m_free==false)
    {
         if(event->x()<=map.m_map_x)
         {
             tower[s].m_free1=true;
         }
         if(tower[s].m_free==true && tower[s].m_free1==true)
         {int x=event->x()-tower[s].m_Rect.width()*0.5;
         int y=event->y()-tower[s].m_Rect.height()*0.5;
         tower[s].setPosition(x,y);
         }
         if(tower[s].m_x>=map.m_map_x && tower[s].m_free==true && tower[s].m_free1==true)
         {
             tower[s].m_free=false;
             int x=GAME_WIDTH*0.5-tower[s].m_Rect.width()*0.5;
             int k=event->y();
             k=k/150;
             int y=150*k;
             tower[s].setPosition(x,y);
             s++;
         }
    }
}

