/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SDLGameObject.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:47 AM
 */

#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include<string>
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
    public:
        SDLGameObject();

        virtual void draw();
        virtual void update();
        virtual void clean();

        virtual void load(const LoaderParams* params);
        
        Vector2D& getPosition();
        int getWidth();
        int getHeight();
        
    protected:

        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;

        int width;
        int height;

        int currentRow;
        int currentFrame;

        int numFrames;
        int animateSpeed;
        std::string textureId;
};

#endif /* SDLGAMEOBJECT_H */

