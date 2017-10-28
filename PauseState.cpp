/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include <string>

#include "header/MainMenuState.h"
#include "header/PauseState.h"
#include "header/Game.h"
#include "header/TextureManager.h"
#include "header/MenuButton.h"
#include "header/StateParser.h"

const std::string PauseState::pauseId = "pause";

void PauseState::pauseToMain()
{
    BlockGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::resumePlay()
{
    BlockGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void PauseState::render()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool PauseState::onEnter()
{
    StateParser stateParser;
    
    stateParser.parseState("config/states.xml", pauseId, &gameObjects, &textureIdList);

    callbacks.push_back(0);
    callbacks.push_back(pauseToMain);
    callbacks.push_back(resumePlay);
    
    setCallbacks(callbacks);

    return true;
}

bool PauseState::onExit()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }
    
    for (int i = 0; i < textureIdList.size(); i++)
    {
        BlocksTextureManager::Instance()->clearFromTextureMap(textureIdList[i]);
    }
    
    return true;
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (dynamic_cast<MenuButton*>(gameObjects[i]))
        {
            MenuButton* button = dynamic_cast<MenuButton*>(gameObjects[i]);
            button->setCallback(callbacks[button->getCallbackId()]);
        }
    }
}

std::string PauseState::getStateId() const
{
    return pauseId;
}