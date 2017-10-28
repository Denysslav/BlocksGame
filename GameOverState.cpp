/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/AnimatedGraphic.h"
#include "header/GameOverState.h"
#include "header/Game.h"
#include "header/MenuButton.h"
#include "header/MainMenuState.h"
#include "header/PlayState.h"
#include "header/StateParser.h"

const std::string GameOverState::gameOverId = "gameover";

void GameOverState::render()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

void GameOverState::update()
{   
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

bool GameOverState::onEnter()
{
    StateParser stateParser;
    
    stateParser.parseState("config/states.xml", gameOverId, &gameObjects, &textureIdList);
    
    callbacks.push_back(0);
    callbacks.push_back(gameOverToMain);
    callbacks.push_back(restartPlay);
    
    setCallbacks(callbacks);
    
    
    return true;
}

bool GameOverState::onExit()
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

void GameOverState::gameOverToMain()
{
    BlockGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::restartPlay()
{
    BlockGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
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