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
class CollisionManager
{
public:
    void checkBallBrickCollision(Ball* ball, const std::vector<Layer*>& tileLayers);
};

#endif /* COLLISIONMANAGER_H */

