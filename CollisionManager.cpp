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

void CollisionManager::checkBallBrickCollision(Ball* ball, const std::vector<Layer*>& tileLayers)
{
    if (!ball->getGameBegin())
    {
        return;
    }
    
    bool isMovingUp = false;
    for (int i = 0; i < tileLayers.size(); i++)
    {
        TileLayer* tileLayer;
        if (!dynamic_cast<TileLayer*>(tileLayers[i]))
        {
            continue;
        }
        
        tileLayer = dynamic_cast<TileLayer*>(tileLayers[i]);

        std::vector<std::vector<int> > tiles = tileLayer->getTileIds();

        int tileColumn, tileRow, tileId = 0;

        if (ball->getVelocity().getY() >= 0)
        {
            isMovingUp = false;
            tileColumn = ball->getPosition().getX() / tileLayer->getTileSize();
            tileRow = (ball->getPosition().getY() + ball->getHeight()) / tileLayer->getTileSize();
            tileId = tiles[tileRow][tileColumn];
        }
        else if (ball->getVelocity().getY() < 0)
        {
            isMovingUp = true;
            tileColumn = ball->getPosition().getX() / tileLayer->getTileSize();
            tileRow = ball->getPosition().getY() / tileLayer->getTileSize();
            tileId = tiles[tileRow][tileColumn ];
        }
        
        if (tileId != 0)
        {
            float brickX = tileColumn * tileLayer->getTileSize();
            float brickY = tileRow * tileLayer->getTileSize();

            if (isMovingUp)
            {
//                if (checkRectangleCollision(brickX, brickY, tileLayer->getTileSize(), tileLayer->getTileSize(),
//                                            ball->getPosition().getX(), ball->getPosition().getY(), ball->getWidth() / 2, ball->getHeight() / 2))
//                {
                    ball->setVelocityY(ball->getVelocity().getY() * -1.);
//                }
            }
            else
            {
//                if (checkRectangleCollision(brickX, brickY, tileLayer->getTileSize(), tileLayer->getTileSize(),
//                                            ball->getPosition().getX(), ball->getPosition().getY(), ball->getWidth() / 2, ball->getHeight() / 2))
//                {
                    ball->setVelocityY(ball->getVelocity().getY() * -1.);
//                }
            }
            tiles[tileRow][tileColumn] = 0;
            tileLayer->setTileIds(tiles);
        }
    }
}

void CollisionManager::checkBallWallCollision(Ball* ball)
{
    if (ball->getGameBegin())
    {            
        float ballXv = ball->getVelocity().getX();
        float ballYv = ball->getVelocity().getY();
        
        if (ball->getPosition().getY() <= 0)
        {
            if (ballYv < 0)
            {
                ballYv *= -1.;
            }
            ball->setVelocityY(ballYv);
        }
        else if (ball->getPosition().getX() <= 0)
        {
            if (ballXv < 0)
            {
                ballXv *= -1.;
            }
            ball->setVelocityX(ballXv);

        }
        else if (ball->getPosition().getX() >= BlockGame::Instance()->getGameWidth() - ball->getWidth())
        {
            if (ballXv > 0)
            {
                ballXv *= -1.;
            }
            ball->setVelocityX(ballXv);
        }
    }
}

bool CollisionManager::checkBallPaddleCollision(Ball* ball, Player* paddle)
{
    if (!ball->getGameBegin()) { return false; }
    
    float ballLeft, ballRight, ballTop, ballBottom;
    float paddleLeft, paddleRight, paddleTop, paddleBottom;
    
    ballLeft = ball->getPosition().getX();
    ballRight = ball->getPosition().getX() + ball->getWidth();
    ballTop = ball->getPosition().getY();
    ballBottom = ball->getPosition().getY() + ball->getHeight();
    
    paddleLeft = paddle->getPosition().getX();
    paddleRight = paddle->getPosition().getX() + paddle->getWidth();
    paddleTop = paddle->getPosition().getY();
    paddleBottom = paddle->getPosition().getY() + paddle->getHeight();

    if ((ballLeft > paddleLeft+paddle->getWidth() 
            || ballLeft+ball->getWidth() < paddleLeft 
            || ballTop > paddleTop+paddle->getHeight() 
            || ballTop+ball->getHeight() < paddleTop))
    {
        return false;
    }

    float ballCenterX = ball->getPosition().getX() + ball->getWidth() / 2;
    float paddleCenterX = paddle->getPosition().getX() + paddle->getWidth() / 2;
    float speedX = ball->getVelocity().getX();
    float speedY = ball->getVelocity().getY();
    
    float speedXY = sqrt(speedX * speedX + speedY * speedY);
    float posX = (ballCenterX - paddleCenterX) / (paddle->getWidth() / 2);
    float influenceX = .75;
    
    speedX = speedXY * posX * influenceX;
    ball->setVelocityX(speedX);
     
    ball->setVelocityY(-1.5);

    return true;
}

bool CollisionManager::checkRectangleCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
    return !(x1 > x2 + w2 || x1 + w1 < x2 || y1 > y2 + h2 || y1 + h1 < y2);
}
