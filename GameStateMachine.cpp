/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/GameStateMachine.h"

void GameStateMachine::pushState(GameState* state)
{
    gameStates.push_back(state);
    gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if (!gameStates.empty())
    {
        if (gameStates.back()->onExit())
        {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }
}

void GameStateMachine::changeState(GameState* state)
{
    if (!gameStates.empty())
    {
        if (gameStates.back()->getStateId() == state->getStateId())
        {
            return;
        }
        
        if (gameStates.back()->onExit())
        {
//            delete gameStates.back();
            gameStates.pop_back();
        }
        
        gameStates.push_back(state);
        gameStates.back()->onEnter();
    }
}

void GameStateMachine::update()
{
    if (!gameStates.empty())
    {
        gameStates.back()->update();
    }
}

void GameStateMachine::render()
{
    if (!gameStates.empty())
    {
        gameStates.back()->render();
    }
}

GameState* GameStateMachine::getCurrentState()
{
    return gameStates.back();
}