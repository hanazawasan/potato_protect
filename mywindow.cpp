#include "mywindow.h"

Mywindow::Mywindow(QWidget *parent) : QMainWindow(parent)
{
    //设置次场景的大小，标题
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);


    MainScene * scene=new MainScene;
    Mybutton * bin=new Mybutton(":/pics/button.png");
    bin->setParent(this);
    bin->move(1000,200);
    connect(bin,&QPushButton::clicked,this,[=](){       
       this->close();
       scene->show();
    });
}

void Mywindow::paintEvent(QPaintEvent *)//画出次场景
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/pics/scene.jpg"));
}
