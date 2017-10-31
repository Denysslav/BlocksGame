/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include<string>
#include "header/SDLGameObject.h"
#include "header/Game.h"

SDLGameObject::SDLGameObject() : GameObject()
{
    
}

void SDLGameObject::load(const LoaderParams* params)
{
    position = Vector2D(params->getX(), params->getY());
    velocity = Vector2D(0., 0.);
    acceleration = Vector2D(0., 0.);
    width = params->getWidth();
    height = params->getHeight();
    textureId = params->getTextureId();
    currentRow = 1;
    currentFrame = 1;
    numFrames = params->getNumFrames();
    animateSpeed = params->getAnimateSpeed();
}

void SDLGameObject::draw()
{
    BlocksTextureManager::Instance()->drawFrame(textureId,
                                                   (int)position.getX(),
                                                   (int)position.getY(),
                                                   width,
                                                   height,
                                                   currentRow,
                                                   currentFrame,
                                                   BlockGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    velocity += acceleration;
    position += velocity;    
}

void SDLGameObject::clean(){}

Vector2D& SDLGameObject::getPosition()
{
    return position;
}

int SDLGameObject::getWidth()
{
    return width;
}

int SDLGameObject::getHeight()
{
    return height;
}

