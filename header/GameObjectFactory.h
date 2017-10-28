/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObjectFactory.h
 * Author: denislav
 *
 * Created on October 27, 2017, 12:10 AM
 */

#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include<string>
#include<map>
#include "BaseCreator.h"

class GameObjectFactory
{
public:
    bool registerType(std::string typeId, BaseCreator* creator);
    GameObject* create(std::string typeId);
    static GameObjectFactory* Instance()
    {
        if (sInstance == 0)
        {
            sInstance = new GameObjectFactory();
            return sInstance;
        }
        
        return sInstance;
    }
private:
    GameObjectFactory(){}
    
    static GameObjectFactory* sInstance;
    std::map<std::string, BaseCreator*> creators;
};

typedef GameObjectFactory BlockGameObjectFactory;

#endif /* GAMEOBJECTFACTORY_H */

