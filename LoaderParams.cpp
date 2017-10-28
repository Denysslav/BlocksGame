/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<string>
#include "header/LoaderParams.h"


LoaderParams::LoaderParams(int x, int y, int w, int h, std::string textureId, int numFrames, int callbackId, int animateSpeed)
: x(x), 
  y(y), 
  width(w), 
  height(h), 
  textureId(textureId), 
  numFrames(numFrames), 
  callbackId(callbackId), 
  animateSpeed(animateSpeed)
{
}

int LoaderParams::getX() const
{
    return x;
}

int LoaderParams::getY() const
{
    return y;
}

int LoaderParams::getWidth() const
{
    return width;
}

int LoaderParams::getHeight() const
{
    return height;
}

std::string LoaderParams::getTextureId() const
{
    return textureId;
}

int LoaderParams::getNumFrames() const
{
    return numFrames;
}

int LoaderParams::getCallbackId() const
{
    return callbackId;
}

int LoaderParams::getAnimateSpeed() const
{
    return animateSpeed;
}