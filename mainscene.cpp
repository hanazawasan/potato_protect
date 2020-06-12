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

    srand((unsigned int)time(NULL));
    recorder=0;

    //背景音乐的播放
    /*QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/backgroudmusic.mp3"));
    player->setVolume(30);
    player->play();*/

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int i=0;i<5;i++)
    {
        if(i%2==0)
        {painter.drawPixmap(200*i,0,map.m_map);}
        else painter.drawPixmap(200*i,0,QPixmap(":/pics/green.png"));
    }

    for(int i=0;i<TOWER_NUM;i++)
    {painter.drawPixmap(tower[i].m_x,tower[i].m_y,tower[i].m_Tower);}
    for(int i=0;i<TOWER_NUM;i++)
    {painter.drawPixmap(tower1[i].m_x,tower1[i].m_y,tower1[i].m_Tower);}


    for(int j=0;j<TOWER_NUM;j++)
    {for(int i = 0 ;i < BULLET_NUM;i++)
    { //如果子弹状态为非空闲，计算发射位置
        int m=tower[j].m_x/200;
        tower[j].hit[m]=hit[m];
        if(tower[j].m_free==false && hit[m]==true)
        {if(!tower[j].m_bullets[i].m_Free)
        {
         painter.drawPixmap(tower[j].m_bullets[i].m_x,tower[j].m_bullets[i].m_y,tower[j].m_bullets[i].m_Bullet );
        }
        }

    }
    }


    //二类塔的子弹
    for(int j=0;j<TOWER_NUM;j++)
    {
    for(int i = 0 ;i < BULLET_NUM;i++)     
    {
        int m=tower1[j].m_x/200;

        for(int k=-1;k<2;k++)
        {
            if(hit[m+k]==true)
            {tower1[j].hit[m]=true;break;}
            else tower1[j].hit[m]=false;
        }
        //如果子弹状态为非空闲，计算发射位置
        if(tower1[j].m_free==false && tower1[j].hit[m]==true)
        {

            if(!tower1[j].m_bullets1[i].m_Free)
            {
            painter.drawPixmap(tower1[j].m_bullets1[i].m_x,tower1[j].m_bullets1[i].m_y,tower1[j].m_bullets1[i].m_Bullet );
            }
            if(!tower1[j].m_bullets2[i].m_Free)
            {
            painter.drawPixmap(tower1[j].m_bullets2[i].m_x,tower1[j].m_bullets2[i].m_y,tower1[j].m_bullets2[i].m_Bullet );
            }
            if(!tower1[j].m_bullets3[i].m_Free)
            {
            if(tower1[j].m_bullets3[i].m_x<=1000)
            painter.drawPixmap(tower1[j].m_bullets3[i].m_x,tower1[j].m_bullets3[i].m_y,tower1[j].m_bullets3[i].m_Bullet );
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
    if(kill>=KILL_ENERMY)
    {
        for(int i=0;i<ENERMY_NUM;i++)
        {
            if(!enermy1[i].m_Free)
            {
                painter.drawPixmap(enermy1[i].m_x,enermy1[i].m_y,enermy1[i].m_enermy);
            }
        }
    }

    painter.setPen(QPen(Qt::red)); 
    painter.drawText(QRect(0,0,200,25),QString("MONEY:%1").arg(money));
    painter.drawText(QRect(400,0,200,25),QString("HP:%1").arg(blood));
    painter.drawText(QRect(800,0,200,25),QString("kill:%1").arg(kill));
    painter.drawText(QRect(1050,160,200,25),QString("  $:%1").arg(TOWER_PRICE));
    painter.drawText(QRect(1050,350,200,25),QString("  $:%1").arg(TOWER1_PRICE));
}


void MainScene::playGame()
{
    m_Timer.start();
    connect(&m_Timer,&QTimer::timeout,[=](){
        enermyToScene();
        updatePosition();
        update();
        road();
        bomb();
        bomb1();
        blood_decrease();
    });
}

void MainScene::updatePosition()
{
    //一类塔
    for(int i=0;i<TOWER_NUM;i++)
    {
        tower[i].shoot();
    }

    for(int j=0;j<TOWER_NUM;j++)
    {
    //更新子弹的坐标
    {for(int i = 0 ;i < BULLET_NUM;i++)
    { //如果子弹状态为非空闲，计算发射位置
        if(!tower[j].m_bullets[i].m_Free)
        { tower[j].m_bullets[i].updatePosition();}
    }
    }
    }

    //二类塔
    for(int i=0;i<TOWER_NUM;i++)
    {
        tower1[i].shoot1();
        tower1[i].shoot2();
        tower1[i].shoot3();
    }

    for(int j=0;j<TOWER_NUM;j++)
    //更新子弹的坐标
    {for(int i = 0 ;i < BULLET_NUM;i++)
    { //如果子弹状态为非空闲，计算发射位置
        if(!tower1[j].m_bullets1[i].m_Free)
        {tower1[j].m_bullets1[i].updatePosition();}
        if(!tower1[j].m_bullets2[i].m_Free)
        {tower1[j].m_bullets2[i].updatePosition();}
        if(!tower1[j].m_bullets3[i].m_Free)
        {tower1[j].m_bullets3[i].updatePosition();}
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

    if(kill>=KILL_ENERMY)
    {
        for(int i=0;i<ENERMY_NUM;i++)
        {
            if(enermy1[i].m_Free==false)
            {
                enermy1[i].updatePosition();
            }
        }
    }
}

void MainScene::enermyToScene()
{
    if(kill>=KILL_ENERMY)
    {
        if(kill>=KILL_ENERMY*2)
        {
            recorder=recorder+10;
        }
        else recorder=recorder+5;
    }
    else recorder++;

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
            int x1=rand()%(1000-enermy[i].m_Rect.width())/200;
            enermy[i].m_x=x1*200;
            enermy[i].m_y=-enermy[i].m_enermy.height();
            break;
        }
    }

    if(kill>=KILL_ENERMY)
    {
        for(int i=0;i<ENERMY_NUM;i++)
        {
            if(enermy1[i].m_Free)
            {
                enermy1[i].m_Free=false;
                int x1=rand()%(1000-enermy1[i].m_Rect.width())/200;
                enermy1[i].m_x=x1*200;
                enermy1[i].m_y=-enermy1[i].m_enermy.height();
                break;
            }
        }
    }


}

void MainScene::bomb()
{       //一类塔
        for(int k=0;k<TOWER_NUM;k++)
        {
            for(int i=0;i<ENERMY_NUM;i++)
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
            {enermy[i].m_Free=true;enermy[i].m_blood=ENERMY_BLOOD;money=money+MONEY_KILLENERMY;kill++;}
            else enermy[i].m_blood--;
            tower[k].m_bullets[j].m_Free = true;
            }
        }
        }
            }

            for(int i=0;i<ENERMY_NUM;i++)
            {
        if(enermy1[i].m_Free)
        {continue;}

        {for(int j=0;j<BULLET_NUM;j++)
        {
            if(tower[k].m_bullets[j].m_Free)
            {continue;}
            if(enermy1[i].m_Rect.intersects(tower[k].m_bullets[j].m_Rect))
            {
            if(enermy1[i].m_blood==0)
            {enermy1[i].m_Free=true;enermy1[i].m_blood=ENERMY1_BLOOD;money=money+MONEY_KILLENERMY*2;kill++;}
            else enermy1[i].m_blood--;
            tower[k].m_bullets[j].m_Free = true;
            }
        }
        }
            }
        }

        //二类塔
        for(int k=0;k<TOWER_NUM;k++)
        {
            for(int i=0;i<ENERMY_NUM;i++)
            {
            if(enermy[i].m_Free)
            {continue;}

            {for(int j=0;j<BULLET_NUM;j++)
            {
            if(tower1[k].m_bullets1[j].m_Free){continue;}

            if(enermy[i].m_Rect.intersects(tower1[k].m_bullets1[j].m_Rect))
            {
            if(enermy[i].m_blood==0)
            {enermy[i].m_Free=true;enermy[i].m_blood=ENERMY_BLOOD;money=money+MONEY_KILLENERMY;kill++;}
            else enermy[i].m_blood--;
            tower1[k].m_bullets1[j].m_Free = true;
            }
            }
            }

            {for(int j=0;j<BULLET_NUM;j++)
            {
            if(tower1[k].m_bullets2[j].m_Free){continue;}

            if(enermy[i].m_Rect.intersects(tower1[k].m_bullets2[j].m_Rect))
            {
            if(enermy[i].m_blood==0)
            {enermy[i].m_Free=true;enermy[i].m_blood=ENERMY_BLOOD;money=money+MONEY_KILLENERMY;kill++;}
            else enermy[i].m_blood--;
            tower1[k].m_bullets2[j].m_Free = true;
            }
            }
            }

            {for(int j=0;j<BULLET_NUM;j++)
            {
            if(tower1[k].m_bullets3[j].m_Free){continue;}

            if(enermy[i].m_Rect.intersects(tower1[k].m_bullets3[j].m_Rect))
            {
            if(enermy[i].m_blood==0)
            {enermy[i].m_Free=true;enermy[i].m_blood=ENERMY_BLOOD;money=money+MONEY_KILLENERMY;kill++;}
            else enermy[i].m_blood--;
            tower1[k].m_bullets3[j].m_Free = true;
            }
            }
            }
            }

            for(int i=0;i<ENERMY_NUM;i++)
            {
            if(enermy1[i].m_Free)
            {continue;}

            {for(int j=0;j<BULLET_NUM;j++)
            {
            if(tower1[k].m_bullets1[j].m_Free){continue;}

            if(enermy1[i].m_Rect.intersects(tower1[k].m_bullets1[j].m_Rect))
            {
            if(enermy1[i].m_blood==0)
            {enermy1[i].m_Free=true;enermy1[i].m_blood=ENERMY1_BLOOD;money=money+MONEY_KILLENERMY;kill++;}
            else enermy1[i].m_blood--;
            tower1[k].m_bullets1[j].m_Free = true;
            }
            }
            }

            {for(int j=0;j<BULLET_NUM;j++)
            {
            if(tower1[k].m_bullets2[j].m_Free){continue;}

            if(enermy1[i].m_Rect.intersects(tower1[k].m_bullets2[j].m_Rect))
            {
            if(enermy1[i].m_blood==0)
            {enermy1[i].m_Free=true;enermy1[i].m_blood=ENERMY1_BLOOD;money=money+MONEY_KILLENERMY;kill++;}
            else enermy1[i].m_blood--;
            tower1[k].m_bullets2[j].m_Free = true;
            }
            }
            }

            {for(int j=0;j<BULLET_NUM;j++)
            {
            if(tower1[k].m_bullets3[j].m_Free){continue;}

            if(enermy1[i].m_Rect.intersects(tower1[k].m_bullets3[j].m_Rect))
            {
            if(enermy1[i].m_blood==0)
            {enermy1[i].m_Free=true;enermy1[i].m_blood=ENERMY1_BLOOD;money=money+MONEY_KILLENERMY;kill++;}
            else enermy1[i].m_blood--;
            tower1[k].m_bullets3[j].m_Free = true;
            }
            }
            }

            }

        }
}

void MainScene::bomb1()
{   //一类塔的碰撞
    for(int i=0;i<TOWER_NUM;i++)
    {
        if(tower[i].m_free==false)
        {
            for(int j=0;j<ENERMY_NUM;j++)
            {
            if(enermy[j].m_Free)
            {
                continue;
            }
            if(enermy[j].m_Rect.intersects(tower[i].m_Rect))
            {
                enermy[j].m_Free=true;
                enermy[j].m_blood=ENERMY_BLOOD;
                money=money+TOWER_AWARD;
                tower[i].setPosition(-300,0);
            }
            }

            for(int j=0;j<ENERMY_NUM;j++)
            {
            if(enermy1[j].m_Free)
            {
                continue;
            }
            if(enermy1[j].m_Rect.intersects(tower[i].m_Rect))
            {
                enermy1[j].m_Free=true;
                enermy1[j].m_blood=ENERMY1_BLOOD;
                money=money+TOWER_AWARD;
                tower[i].setPosition(-300,0);
            }
        }
        }
    }

    //二类塔的碰撞
    for(int i=0;i<TOWER_NUM;i++)
    {
        if(tower1[i].m_free==false)
        {
            for(int j=0;j<ENERMY_NUM;j++)
            {
            if(enermy[j].m_Free)
            {
                continue;
            }
            if(enermy[j].m_Rect.intersects(tower1[i].m_Rect))
            {
                enermy[j].m_Free=true;
                enermy[j].m_blood=ENERMY_BLOOD;
                money=money+TOWER_AWARD;
                tower1[i].setPosition(-300,0);
            }
            }

            for(int j=0;j<ENERMY_NUM;j++)
            {
            if(enermy1[j].m_Free)
            {
                continue;
            }
            if(enermy1[j].m_Rect.intersects(tower1[i].m_Rect))
            {
                enermy1[j].m_Free=true;
                enermy1[j].m_blood=ENERMY1_BLOOD;
                money=money+TOWER_AWARD;
                tower1[i].setPosition(-300,0);
            }
        }
        }
    }

}

void MainScene::blood_decrease()
{
    for(int i=0;i<ENERMY_NUM;i++)
    {
        if(enermy[i].m_Free)
        {continue;}
        else if(enermy[i].m_y>=GAME_HEIGHT-1)
        {blood--;}
    }

    for(int i=0;i<ENERMY_NUM;i++)
    {
        if(enermy1[i].m_Free)
        {continue;}
        else if(enermy1[i].m_y>=GAME_HEIGHT-1)
        {blood--;}
    }
}

void MainScene::road()
{

        for(int i=0;i<5;i++)
        {   hit[i]=false;
            for(int j=0;j<ENERMY_NUM;j++)
            {
                if(enermy[j].m_Free)
                {continue;}
                int m=enermy[j].m_x/200;
                if(m==i)
                {hit[i]=true;}
            }
        }

}

int s=0;
int s1=0;

void MainScene::mousePressEvent(QMouseEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        if(event->x()>1000 && event->y()<200 && money>=tower[s].m_price)
        {
            tower[s].m_free2=true;
        }
        if(event->x()>1000 && event->y()>200 && event->y()<400 && money>=tower1[s1].m_price)
        {
            tower1[s1].m_free2=true;
        }

    }
}
void MainScene::mouseMoveEvent(QMouseEvent *event)
{   if(tower[s].m_free2)
    {if(s==0)
     {
            tower[s].m_free1=true;
            if(tower[s].m_free)
            {
               int x=event->x()-tower[s].m_Rect.width()*0.5;
               int y=event->y()-tower[s].m_Rect.height()*0.5;
               tower[s].setPosition(x,y);
            }

     }
    if(s>=TOWER_NUM)
     {return;}

    if(tower[s-1].m_free==false)
    {
           if(event->x()>=1000)
           {
               tower[s].m_free1=true;
           }
           if(tower[s].m_free==true && tower[s].m_free1==true)
           {int x=event->x()-tower[s].m_Rect.width()*0.5;
           int y=event->y()-tower[s].m_Rect.height()*0.5;
           tower[s].setPosition(x,y);
           }
     }
    }

    if(tower1[s1].m_free2)
    {if(s1==0)
     {
            tower1[s1].m_free1=true;
            if(tower1[s1].m_free)
            {
               int x=event->x()-tower1[s1].m_Rect.width()*0.5;
               int y=event->y()-tower1[s1].m_Rect.height()*0.5;
               tower1[s1].setPosition(x,y);
            }

     }
    if(s1>=TOWER_NUM)
     {return;}

    if(tower1[s1-1].m_free==false)
    {
           if(event->x()>=1000)
           {
               tower1[s1].m_free1=true;
           }
           if(tower1[s1].m_free==true && tower1[s1].m_free1==true)
           {int x=event->x()-tower1[s1].m_Rect.width()*0.5;
           int y=event->y()-tower1[s1].m_Rect.height()*0.5;
           tower1[s1].setPosition(x,y);
           }
      }
    }


}

void MainScene::mouseReleaseEvent(QMouseEvent *event)
{
    if(s>=TOWER_NUM)
    {return;}

    if(event->type()==QEvent::MouseButtonRelease && tower[s].m_free==true && tower[s].m_free1==true && tower[s].m_free2==true)
    {


        if(event->x()>=1000)
        {
            tower[s].setPosition(1000,0);
            tower[s].m_free2=false;
            return;          
        }

        money=money-tower[s].m_price;
        int x=event->x();
        int y=event->y();
        int w=x/200;
        int l=y/150;
        int x1=w*200;
        int y1=l*150;
        tower[s].setPosition(x1,y1);
        tower[s].m_free=false;
        s++;
    }


    if(s1>=TOWER_NUM)
    {return;}

    if(event->type()==QEvent::MouseButtonRelease && tower1[s1].m_free==true && tower1[s1].m_free1==true && tower1[s1].m_free2==true)
    {

        if(event->x()>=1000)
        {
            tower1[s1].setPosition(1000,200);
            tower1[s1].m_free2=false;
            return;
        }

        money=money-tower1[s1].m_price;
        int x=event->x();
        int y=event->y();
        int w=x/200;
        int l=y/150;
        int x1=w*200;
        int y1=l*150;
        tower1[s1].setPosition(x1,y1);
        tower1[s1].m_free=false;
        s1++;
    }
}

