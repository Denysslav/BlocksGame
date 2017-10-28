/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/Game.h"
#include "header/TextureManager.h"
#include "header/MainMenuState.h"
#include "header/StateParser.h"
#include "header/TextureManager.h"
#include "header/PlayState.h"
#include "header/MenuButton.h"

const std::string MainMenuState::menuId = "menu";

void MainMenuState::render()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

void MainMenuState::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

bool MainMenuState::onEnter()
{
    StateParser stateParser;
    
    stateParser.parseState("config/states.xml", menuId, &gameObjects, &textureIdList);
    
    callbacks.push_back(0);
    callbacks.push_back(menuToPlay);
    callbacks.push_back(exitFromMenu);
    
    setCallbacks(callbacks);
    
    return true;
}

bool MainMenuState::onExit()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }
        
    for (int i = 0; i < textureIdList.size(); i++)
    {
        BlocksTextureManager::Instance()->clearFromTextureMap(textureIdList[i]);
    }
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
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

void MainMenuState::menuToPlay()
{
    BlockGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::exitFromMenu()
{
    BlockGame::Instance()->clean();
}

std::string MainMenuState::getStateId() const
{
    return menuId;
}