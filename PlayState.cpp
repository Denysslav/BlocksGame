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

int PlayState::currentLevel = 1;
const std::string PlayState::playId = "play";

void PlayState::update()
{
    bool ballWallCollision = false;
    Ball* ball = dynamic_cast<Ball*>(gameObjects[1]);
    Player* paddle = dynamic_cast<Player*>(gameObjects[0]);
    
    if (BlockInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        BlockGame::Instance()->getStateMachine()->pushState(new PauseState());
    }
    
    if (paddle->getPlayerLives() == 0)
    {
        BlockGame::Instance()->getStateMachine()->changeState(new GameOverState());
    }
    
    int bc = level->getBricksCount();
    
    ballWallCollision = collisionManager.checkBallWallCollision(ball, paddle);
    collisionManager.checkBallPaddleCollision(ball, paddle);
    if (!ballWallCollision)
    {
        collisionManager.checkBallBrickCollision(ball, level->getCollidableLayers(), bc);
    }
    
    std::cout << bc << std::endl;
    if (bc == 0)
    {
        currentLevel += 1;
        LevelParser levelParser;
    
        std::string levelDir = "levels/level";

        char levelNum[2];
        sprintf(levelNum, "%d", currentLevel);

        std::string levelNumStr(levelNum);
        std::string levelExt = ".tmx";

        std::string fullLevelName = levelDir + levelNumStr + levelExt;
        level = levelParser.parseLevel(fullLevelName.c_str());

        ball->setPositionX((BlockGame::Instance()->getGameWidth() / 2) - (ball->getWidth() / 2));
        ball->setPositionY(384.);
        ball->setVelocityX(0.);
        ball->setVelocityY(0.);
        ball->setGameBegin(false);
        
        paddle->setPositionX((BlockGame::Instance()->getGameWidth() / 2) - (paddle->getWidth() / 2));
        paddle->setPositionY(400.);
        paddle->setVelocityX(0.);
        paddle->setVelocityY(0.);
        paddle->setGameBegin(false);
    }
    else
    {
        level->setBricksCount(bc);
    }
    
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
    
    std::string levelDir = "levels/level";
    
    char levelNum[2];
    sprintf(levelNum, "%d", currentLevel);
    
    std::string levelNumStr(levelNum);
    std::string levelExt = ".tmx";
    
    std::string fullLevelName = levelDir + levelNumStr + levelExt;
    
    stateParser.parseState("config/states.xml", playId, &gameObjects, &textureIdList);
    level = levelParser.parseLevel(fullLevelName.c_str());

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