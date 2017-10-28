/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.h
 * Author: denislav
 *
 * Created on October 26, 2017, 12:09 AM
 */

#ifndef BALL_H
#define BALL_H

#include "SDLGameObject.h"
#include "BaseCreator.h"

class Ball : public SDLGameObject
{
    public:
        Ball(bool begin);
        virtual void draw();
        virtual void update();
        virtual void clean();
        virtual void load(const LoaderParams* params);
        
        void setGameBegin(bool begin);
    private:
        bool gameBegin;

};

class BallCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Ball(false);
    }
};

#endif /* BALL_H */

