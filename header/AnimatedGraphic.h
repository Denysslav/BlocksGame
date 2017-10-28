/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnimatedGraphic.h
 * Author: denislav
 *
 * Created on October 26, 2017, 10:04 PM
 */

#ifndef ANIMATEDGRAPHIC_H
#define ANIMATEDGRAPHIC_H

#include "SDLGameObject.h"
#include "BaseCreator.h"

class AnimatedGraphic : public SDLGameObject
{
    public:
        AnimatedGraphic();
        virtual void draw();
        virtual void update();
        virtual void clean();
        
        virtual void load(const LoaderParams* params);
        
};

class AnimatedGraphicCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new AnimatedGraphic();
    }
};

#endif /* ANIMATEDGRAPHIC_H */

