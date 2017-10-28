/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/Enemy.h"

Enemy::Enemy() : SDLGameObject()
{

}

void Enemy::load(const LoaderParams* params)
{
    SDLGameObject::load(params);
}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    position.setX(position.getX() + 1);
    position.setY(position.getY() + 1);

    currentFrame = int(((SDL_GetTicks() / 100) % 5));
}

void Enemy::clean()
{

}