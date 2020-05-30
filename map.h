#ifndef MAP_H
#define MAP_H

#include<QPixmap>

#include "config.h"

class Map
{
public:
    Map();
public:
    QPixmap m_map;
    int m_map_x;
    int m_map_y;
};

#endif // MAP_H
