/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PauseState.h
 * Author: denislav
 *
 * Created on October 26, 2017, 1:45 AM
 */

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include<string>
#include<vector>

class GameObject;

class PauseState : public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateId() const;
    
private:
    static void pauseToMain();
    static void resumePlay();
    
    static const std::string pauseId;
    
    std::vector<GameObject*> gameObjects;
};


#endif /* PAUSESTATE_H */

