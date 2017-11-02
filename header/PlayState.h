/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayState.h
 * Author: denislav
 *
 * Created on October 25, 2017, 10:47 AM
 */

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include<vector>
#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Level.h"
#include "CollisionManager.h"

class PlayState : public GameState
{
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();
        bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
        
        virtual std::string getStateId() const 
        { 
            return playId; 
        }
        
        void startMoving(bool begin);
    private:
        static const std::string playId;
        
        static int currentLevel;
        std::vector<GameObject*> gameObjects;
        
        Level* level;
        CollisionManager collisionManager;
};

#endif /* PLAYSTATE_H */

