/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollisionManager.h
 * Author: denislav
 *
 * Created on October 30, 2017, 1:20 AM
 */

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include<vector>
#include "Layer.h"
#include "Ball.h"
#include "Player.h"

class CollisionManager
{
public:
    void checkBallBrickCollision(Ball* ball, const std::vector<Layer*>& tileLayers, int &brickCount);
    void checkBallWallCollision(Ball* ball, Player* paddle);
    bool checkBallPaddleCollision(Ball* ball, Player* paddle);
    
private:
    bool checkRectangleCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
};

#endif /* COLLISIONMANAGER_H */

