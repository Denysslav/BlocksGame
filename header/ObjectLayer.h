/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ObjectLayer.h
 * Author: denislav
 *
 * Created on October 29, 2017, 11:11 PM
 */

#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include<vector>
#include "Layer.h"
#include "CollisionManager.h"
#include "GameObject.h"

class ObjectLayer : public Layer
{
    public:
        virtual void update(Level* level);
        virtual void render();
        
        std::vector<GameObject*>* getGameObjects()
        {
            return &gameObjects;
        }
    private:
        CollisionManager collisionManager;
        std::vector<GameObject*> gameObjects;
};

#endif /* OBJECTLAYER_H */

