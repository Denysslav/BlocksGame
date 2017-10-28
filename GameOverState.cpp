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

const std::string GameOverState::gameOverId = "GAMEOVER";

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
    if (!BlocksTextureManager::Instance()->load("assets/game_over.png", "gameovertext", BlockGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if (!BlocksTextureManager::Instance()->load("assets/main.png", "mainbutton", BlockGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if (!BlocksTextureManager::Instance()->load("assets/restart.png", "restartbutton", BlockGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    GameObject* gameOverText = new AnimatedGraphic();
    GameObject* button1 = new MenuButton();
    GameObject* button2 = new MenuButton();
    
    gameOverText->load(new LoaderParams(200, 100, 240, 35, "gameovertext", 1, 0, 2));
    button1->load(new LoaderParams(245, 200, 165, 80, "mainbutton", 1, 0, 0));
    button2->load(new LoaderParams(240, 300, 175, 80, "restartbutton", 1, 0, 0));
    
    gameObjects.push_back(gameOverText);
    gameObjects.push_back(button1);
    gameObjects.push_back(button2);
    
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