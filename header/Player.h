/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:47 AM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "SDLGameObject.h"
#include "BaseCreator.h"

class Player : public SDLGameObject
{
    public:
        Player();
        virtual void draw();
        virtual void update();
        virtual void clean();
        
        virtual void load(const LoaderParams* params);
        
        void setGameBegin(bool begin);
    private:
        bool gameBegin;
};

class PlayerCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Player();
    }
};

#endif /* PLAYER_H */

