/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Level.h
 * Author: denislav
 *
 * Created on October 29, 2017, 12:06 AM
 */

#ifndef LEVEL_H
#define LEVEL_H

#include<string>
#include<vector>
#include "Layer.h"
#include "Ball.h"
#include "Player.h"

struct Tileset
{
   int firstGridId;
   int tileWidth;
   int tileHeight;
   int spacing;
   int margin;
   int width;
   int height;
   int numColumns;
   std::string name;
};

class Level
{
public:
    ~Level();
    
    void update();
    void render();
    
    std::vector<Tileset>* getTilesets()
    {
        return &tilesets;
    }
    
    std::vector<Layer*>* getLayers()
    {
        return &layers;
    }
    
    const std::vector<Layer*>& getCollidableLayers()
    {
        return layers;
    }
    
    void setBall(Ball* b)
    {
        ball = b;
    }
    
    Ball* getBall()
    {
        return ball;
    }
    
    void setPaddle(Player* p)
    {
        paddle = p;
    }
    
    Player* getPaddle()
    {
        return paddle;
    }
    
    void setBricksCount(int bircksCount)
    {
        bricks = bircksCount;
    }
    
    int getBricksCount()
    {
        return bricks;
    }
    
private:
    Level(){};
    friend class LevelParser;
    
    int bricks;
    
    Ball* ball;
    Player* paddle;
    
    std::vector<Tileset> tilesets;
    std::vector<Layer*> layers;
};

#endif /* LEVEL_H */

