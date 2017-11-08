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
const int PlayState::maxLevel = 2;

void PlayState::update()
{
    if (BlockInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        BlockGame::Instance()->getStateMachine()->pushState(new PauseState());
    }
    
    checkCollision();
    
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
    
    Player* paddle = dynamic_cast<Player*>(gameObjects[0]);
 
    char livesNum[15];
    char scoreNum[15];
    
    sprintf(livesNum, "Lives: %d", paddle->getPlayerLives());
    sprintf(scoreNum, "Score: %d", paddle->getScore());

    BlocksTextureManager::Instance()->drawText(10, 5, livesNum, &textObjects[0], BlockGame::Instance()->getRenderer());
    BlocksTextureManager::Instance()->drawText(100, 5, scoreNum, &textObjects[1], BlockGame::Instance()->getRenderer());

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

    SDL_Rect livesRect;
    SDL_Rect scoreRect;
    
    textObjects.push_back(livesRect);
    textObjects.push_back(scoreRect);
    
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

void PlayState::startMoving(bool begin)
{
    Player* p = dynamic_cast<Player*>(gameObjects[0]);
    p->setGameBegin(true);
    
    Ball* b = dynamic_cast<Ball*>(gameObjects[1]);
    b->setGameBegin(true);
    
}

void PlayState::checkCollision()
{
    Ball* ball = dynamic_cast<Ball*>(gameObjects[1]);
    Player* paddle = dynamic_cast<Player*>(gameObjects[0]);
    
    if (paddle->getPlayerLives() == 0)
    {
        BlockGame::Instance()->getStateMachine()->changeState(new GameOverState());
    }
    
    int bc = level->getBricksCount();
    bool hasBallWallCollision = false,
         hasBallPaddleCollision = false;
    int hasBallBrickCollision = 0;
    
    hasBallWallCollision = collisionManager.checkBallWallCollision(ball, paddle);
    hasBallPaddleCollision = collisionManager.checkBallPaddleCollision(ball, paddle);
    if (!hasBallWallCollision)
    {
        hasBallBrickCollision = collisionManager.checkBallBrickCollision(ball, level->getCollidableLayers(), bc);
    }
    
    if (bc == 0)
    {
        currentLevel += 1;
        if (currentLevel > maxLevel)
        {
            currentLevel = maxLevel;
        }
        
        LevelParser levelParser;
    
        std::string levelDir = "levels/level";

        char levelNum[2];
        sprintf(levelNum, "%d", currentLevel);

        std::string levelNumStr(levelNum);
        std::string levelExt = ".tmx";

        std::string fullLevelName = levelDir + levelNumStr + levelExt;
        level = levelParser.parseLevel(fullLevelName.c_str());
        
        resetStateDefault(ball, paddle);
    }
    else
    {
        if (hasBallWallCollision)
        {
            BlockSoundManager::Instance()->playSound("wall_hit", 0);
        }
        else if (hasBallBrickCollision != 0)
        {
            paddle->setScore(paddle->getScore() + hasBallBrickCollision);

            BlockSoundManager::Instance()->playSound("brick_hit", 0);
        }
        else if (hasBallPaddleCollision)
        {
            BlockSoundManager::Instance()->playSound("paddle_hit", 0);
        }
        
        level->setBricksCount(bc);
    }
}

void PlayState::resetStateDefault(Ball* ball, Player* paddle)
{
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