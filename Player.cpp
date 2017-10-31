/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/Player.h"
#include "header/InputHandler.h"
#include "header/Vector2D.h"
#include "header/Game.h"

Player::Player() : SDLGameObject()
{
    gameBegin = false;
//    currentFrame = 0;
}

void Player::load(const LoaderParams* params)
{
    SDLGameObject::load(params);
}

void Player::draw()
{
    currentFrame = 0;

    SDLGameObject::draw();
}

void Player::update()
{
    if (gameBegin)
    {
        Vector2D* vec = BlockInputHandler::Instance()->getMousePosition();

        if (position.getX() >= BlockGame::Instance()->getGameWidth() - width
                || position.getX() <= 0)
        {
            position.setX(BlockGame::Instance()->getGameWidth() - (width + 1));
            velocity.setX(-0.1);
        }
        else
        {
            velocity.setX((vec->getX() - position.getX()) / 25);        
        }
    }
 
    SDLGameObject::update();
    
}

void Player::clean()
{
}

void Player::setGameBegin(bool begin)
{
    gameBegin = begin;
}