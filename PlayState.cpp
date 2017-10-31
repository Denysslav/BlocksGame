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
#include "header/StateParser.h"
#include "header/LevelParser.h"

const std::string PlayState::playId = "play";

void PlayState::update()
{
    if (BlockInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        BlockGame::Instance()->getStateMachine()->pushState(new PauseState());
    }
    
    collisionManager.checkBallWallCollision(dynamic_cast<Ball*>(gameObjects[1]));
    collisionManager.checkBallPaddleCollision(dynamic_cast<Ball*>(gameObjects[1]), dynamic_cast<Player*>(gameObjects[0]));
    collisionManager.checkBallBrickCollision(dynamic_cast<Ball*>(gameObjects[1]), level->getCollidableLayers());
    
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
    
    level->update();
}

void PlayState::render()
{
    level->render();

    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
    StateParser stateParser;
    LevelParser levelParser;
    
    stateParser.parseState("config/states.xml", playId, &gameObjects, &textureIdList);
    level = levelParser.parseLevel("config/level1.tmx");

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