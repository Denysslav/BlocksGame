/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/Player.h"
#include "header/InputHandler.h"
#include "header/Vector2D.h"

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

        velocity.setX((vec->getX() - position.getX()) / 50);

        SDLGameObject::update();
    }
    
}

void Player::clean()
{
}

void Player::setGameBegin(bool begin)
{
    gameBegin = begin;
}