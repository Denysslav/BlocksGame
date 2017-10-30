/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/Ball.h"

Ball::Ball() : SDLGameObject()
{
}

void Ball::load(const LoaderParams* params)
{
    gameBegin = false;
    SDLGameObject::load(params);
}

void Ball::draw()
{
    currentFrame = 0;

    SDLGameObject::draw();
}

void Ball::update()
{
    if (gameBegin)
    {
        if (position.getY() < 0)
        {
            velocity.setX(0.5);
             velocity.setY(1.5);
        } 
        else if (position.getY() >= 380)
        {
            velocity.setX(-0.5);

            velocity.setY(-1.5);
        }
    }

    SDLGameObject::update();
}

void Ball::clean()
{
}

void Ball::setGameBegin(bool begin)
{
    gameBegin = begin;
}