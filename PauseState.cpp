/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>

#include "header/MainMenuState.h"
#include "header/PauseState.h"
#include "header/Game.h"
#include "header/TextureManager.h"
#include "header/MenuButton.h"

const std::string PauseState::pauseId = "PAUSE";

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
    if (!BlocksTextureManager::Instance()->load("assets/resume.png", "resumebutton", BlockGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if (!BlocksTextureManager::Instance()->load("assets/main.png", "mainbutton", BlockGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    GameObject* button1 = new MenuButton();
    GameObject* button2 = new MenuButton();
    
    button1->load(new LoaderParams(230, 190, 163, 65, "mainbutton", 1, 0, 0));
    button2->load(new LoaderParams(230, 290, 160, 65, "resumebutton", 1, 0, 0));
    
    gameObjects.push_back(button1);
    gameObjects.push_back(button2);
    
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

std::string PauseState::getStateId() const
{
    return pauseId;
}