/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameStateMachine.h
 * Author: denislav
 *
 * Created on October 25, 2017, 10:54 AM
 */

#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include<vector>
#include "GameState.h"

class GameStateMachine
{
public:
    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();
    void render();
    void update();
    GameState* getCurrentState();
    
private:
    std::vector<GameState*> gameStates;
};

#endif /* GAMESTATEMACHINE_H */

