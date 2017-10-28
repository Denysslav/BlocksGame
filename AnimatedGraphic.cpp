/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic() : SDLGameObject()
{
    
}

void AnimatedGraphic::load(const LoaderParams* params)
{
    SDLGameObject::load(params);
    animateSpeed = params->getAnimateSpeed();
}

void AnimatedGraphic::draw()
{
    SDLGameObject::draw();
}

void AnimatedGraphic::update()
{
   currentFrame = int(((SDL_GetTicks() / (1000 / animateSpeed)) % numFrames));
}

void AnimatedGraphic::clean()
{
    
}