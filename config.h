#ifndef CONFIG_H
#define CONFIG_H

//游戏的窗口大小
#define GAME_WIDTH 1200
#define GAME_HEIGHT 1500
#define GAME_TITLE "保卫家园"

//定时器的设定
#define GAME_RATE 10

//一类子弹的设定
#define BULLET_SPEED 8
#define BULLET_NUM 30
#define BULLET_INTERVAL 80

//二类子弹的设定
#define BULLET1_SPEED 8
#define BULLET1_INTERVAL 80

//一类敌人的设定
#define ENERMY_SPEED 2
#define ENERMY_NUM 20
#define ENERMY_INTERVAL 300
#define ENERMY_BLOOD 6

//二类敌人的设定

#define ENERMY1_SPEED 2
#define ENERMY1_BLOOD 6



//一类防御塔的设定
#define TOWER_NUM 30
#define TOWER_PRICE 50
#define TOWER_AWARD 30

//二类防御塔的设定
#define TOWER1_PRICE 200
#define TOWER1_AWARD 30


//金钱的设定
#define MONEY_START 100
#define MONEY_KILLENERMY 30
#define MONEY_INCREASE 1

//家的设定
#define HOME_BLOOD 10

//击杀敌人数的判定
#define KILL_ENERMY 60

#endif // CONFIG_H
