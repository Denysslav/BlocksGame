/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/PlayState.h"
#include "header/PauseState.h"
#include "header/GameOverState.h"
#include "header/InputHandler.h"
#include "header/TextureManager.h"
#include "header/Game.h"
#include "header/Player.h"
#include "header/Ball.h"

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
    if (BlockInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        BlockGame::Instance()->getStateMachine()->pushState(new PauseState());
    }
    
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void PlayState::render()
{
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{

    if (!BlocksTextureManager::Instance()->load("assets/paddle.png", "paddle", BlockGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    if(!BlocksTextureManager::Instance()->load("assets/ball.png", "ball", BlockGame::Instance()->getRenderer()))
    {        
        return false;
    }
    
    GameObject* player = new Player();
    GameObject* ball = new Ball(false);
    
    player->load(new LoaderParams(264, 400, 98, 31, "paddle"));
    ball->load(new LoaderParams(300, 380, 24, 24, "ball"));
    
    gameObjects.push_back(player);
    gameObjects.push_back(ball);
    
    return true;
}

bool PlayState::onExit()
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

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();
    
    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();
    
    if (bottomA <= topB) { return false; }
    if (topA >= bottomB) { return false; }
    if (leftA >= rightB) { return false; }
    if (rightA <= leftB) { return false; }
    
    return true;
}

void PlayState::startMoving(bool begin)
{
    Player* p = dynamic_cast<Player*>(gameObjects[0]);
    p->setGameBegin(true);
    
    Ball* b = dynamic_cast<Ball*>(gameObjects[1]);
    b->setGameBegin(true);
    
}