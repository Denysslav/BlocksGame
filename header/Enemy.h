/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:46 AM
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "SDLGameObject.h"
#include "BaseCreator.h"

class Enemy : public SDLGameObject
{
    public:
    Enemy();
        virtual void draw();
        virtual void update();
        virtual void clean();
        virtual void load(const LoaderParams* params);
};

class EnemyCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Enemy();
    }
};

#endif /* ENEMY_H */

