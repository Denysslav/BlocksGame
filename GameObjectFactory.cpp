/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/GameObjectFactory.h"
 
GameObjectFactory* GameObjectFactory::sInstance = 0;

bool GameObjectFactory::registerType(std::string typeId, BaseCreator* creator)
{
    std::map<std::string, BaseCreator*>::iterator it = creators.find(typeId);
    // If creator is already registered, do nothing
    if (it != creators.end())
    {
        delete creator;
        return false;
    }
    
    creators[typeId] = creator;
    
    return true;
}

GameObject* GameObjectFactory::create(std::string typeId)
{
    std::map<std::string, BaseCreator*>::iterator it = creators.find(typeId);
    if (it == creators.end())
    {
        return NULL;
    }
    
    BaseCreator* creator = (*it).second;
    
    return creator->createGameObject();
}