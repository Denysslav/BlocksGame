/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameOverState.h
 * Author: denislav
 *
 * Created on October 26, 2017, 10:12 PM
 */

#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <string>
#include <vector>
#include "GameObject.h"
#include "MenuState.h"

class GameObject;

class GameOverState : public MenuState
{
    virtual void render();
    virtual void update();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateId() const
    {
        return gameOverId;
    }
    
private:
    static void gameOverToMain();
    static void restartPlay();
    
    static const std::string gameOverId;
    
    virtual void setCallbacks(const std::vector<Callback>& callbacks);
    
    std::vector<GameObject*> gameObjects;
};

#endif /* GAMEOVERSTATE_H */

