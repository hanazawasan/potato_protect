#include "map.h"

Map::Map()
{
    m_map.load(":/pics/blue.png");
    m_map_x=GAME_WIDTH*0.5-m_map.width()*0.5;
    m_map_y=0;
}
