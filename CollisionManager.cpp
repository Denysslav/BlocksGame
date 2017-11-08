/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include<cmath>
#include "header/Game.h"
#include "header/CollisionManager.h"
#include "header/SDLGameObject.h"
#include "header/TileLayer.h"

CollisionManager::CollisionManager()
{
    brickWeights.push_back(0);
    brickWeights.push_back(10);
    brickWeights.push_back(20);
    brickWeights.push_back(30);

}
int CollisionManager::checkBallBrickCollision(Ball* ball, const std::vector<Layer*>& tileLayers, int &brickCount)
{
    if (!ball->getGameBegin())
    {
        return false;
    }
    
    float ballLeftX = ball->getPosition().getX();
    float ballLeftY = ball->getPosition().getY() + ball->getHeight() / 2;
    float ballRightX = ball->getPosition().getX() + ball->getWidth();
    float ballRightY = ball->getPosition().getY() + ball->getHeight() / 2;
    float ballTopX = ball->getPosition().getX() + ball->getWidth() / 2;
    float ballTopY = ball->getPosition().getY();
    float ballBottomX = ball->getPosition().getX() + ball->getWidth() / 2;
    float ballBottomY = ball->getPosition().getY() + ball->getHeight();
    
    int& bc = const_cast<int&>(brickCount);
    
    int hasCollision = 0;
    for (int i = 0; i < tileLayers.size(); i++)
    {
        TileLayer* tileLayer;
        if (!dynamic_cast<TileLayer*>(tileLayers[i]))
        {
            continue;
        }
        
        tileLayer = dynamic_cast<TileLayer*>(tileLayers[i]);

        std::vector<std::vector<int> > tiles = tileLayer->getTileIds();

        int tileColumn, tileRow, tileRow2, tileColumn2, tileRow3, tileColumn3, tileRow4, tileColumn4;
        
        tileColumn = ballTopX / tileLayer->getTileSize();
        tileRow = ballTopY / tileLayer->getTileSize();

        tileColumn2 = ballBottomX / tileLayer->getTileSize();
        tileRow2 = ballBottomY / tileLayer->getTileSize(); 

        tileColumn3 = ballLeftX / tileLayer->getTileSize();
        tileRow3 = ballLeftY / tileLayer->getTileSize();

        tileColumn4 = ballRightX / tileLayer->getTileSize();
        tileRow4 = ballRightY / tileLayer->getTileSize();

        if (tiles[tileRow][tileColumn] != 0)
        {
            hasCollision = brickWeights[tiles[tileRow][tileColumn]];
            bc -= 1;
            
            tiles[tileRow][tileColumn] = 0;
            ball->setVelocityY(ball->getVelocity().getY() * -1.);
        }
        
        if (tiles[tileRow2][tileColumn2] != 0)
        {
            hasCollision = brickWeights[tiles[tileRow2][tileColumn2]];
            bc -= 1;
            tiles[tileRow2][tileColumn2] = 0;
            ball->setVelocityY(ball->getVelocity().getY() * -1.);
        }
        
        if (tiles[tileRow3][tileColumn3] != 0)
        {
            hasCollision = brickWeights[tiles[tileRow3][tileColumn3]];
            bc -= 1;
            tiles[tileRow3][tileColumn3] = 0;
            ball->setVelocityX(ball->getVelocity().getX() * -1.);
        }
        
        if (tiles[tileRow4][tileColumn4] != 0)
        {
            hasCollision = brickWeights[tiles[tileRow4][tileColumn4]];
            bc -= 1;
            tiles[tileRow4][tileColumn4] = 0;
            ball->setVelocityX(ball->getVelocity().getX() * -1.);
        }

        tileLayer->setTileIds(tiles);
    }
    
    return hasCollision;
}

bool CollisionManager::checkBallWallCollision(Ball* ball, Player* paddle)
{
    if (!ball->getGameBegin()) { return false; }
    
    if (((ball->getVelocity().getX() < 0) && (ball->getPosition().getX() <= 0))
            || ((ball->getVelocity().getX() > 0) && (ball->getPosition().getX() > BlockGame::Instance()->getGameWidth() - ball->getWidth())))
    {
        ball->setVelocityX(ball->getVelocity().getX() * -1.);
        return true;
    }
    
    if ((ball->getVelocity().getY() < 0) && (ball->getPosition().getY() <= 0))
    {
        ball->setVelocityY(ball->getVelocity().getY() * -1.);
        return true;
    }
    
    if (ball->getPosition().getY() >= BlockGame::Instance()->getGameHeight() - ball->getHeight())
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
        
        paddle->setPlayerLives(paddle->getPlayerLives() - 1);
        return true;
    }
    
    return false;
}

bool CollisionManager::checkBallPaddleCollision(Ball* ball, Player* paddle)
{
    if (!ball->getGameBegin()) { return false; }
    
    float ballX, ballY, ballWidth, ballHeight;
    float paddleX, paddleY, paddleWidth, paddleHeight;
    
    ballX = ball->getPosition().getX();
    ballY = ball->getPosition().getY();
    ballWidth = ball->getWidth();
    ballHeight = ball->getHeight();
    
    paddleX = paddle->getPosition().getX();
    paddleY = paddle->getPosition().getY();
    paddleWidth = paddle->getWidth();
    paddleHeight = paddle->getHeight();
    

    if ((ball->getVelocity().getY() > 0) && (ballY + ballHeight >= paddleY)
            && (ballY + ballHeight <= paddleHeight + paddleY))
    {
        if ((ballX <= paddleX + paddleWidth) && (ballX + ballWidth >= paddleX))
        {
            float ballCenterX = ball->getPosition().getX() + ball->getWidth() / 2;
            float paddleCenterX = paddle->getPosition().getX() + paddle->getWidth() / 2;
            float speedX = ball->getVelocity().getX();
            float speedY = ball->getVelocity().getY();

            float speedXY = sqrt(speedX * speedX + speedY * speedY);
            float posX = (ballCenterX - paddleCenterX) / (paddle->getWidth() / 2);
            float influenceX = 1.;

            speedX = speedXY * posX * influenceX;
            ball->setVelocityX(speedX);
            ball->setVelocityY(ball->getVelocity().getY() * -1.);
            
            return true;
        }
    }
    return false;
}

bool CollisionManager::checkRectangleCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
    return !(x1 > x2 + w2 || x1 + w1 < x2 || y1 > y2 + h2 || y1 + h1 < y2);
}
