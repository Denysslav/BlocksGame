/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObject.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:46 AM
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<string>
#include "SDL2/SDL.h"
#include "LoaderParams.h"

class GameObject
{
    public:
        virtual ~GameObject(){}
        
        virtual void draw()=0;
        virtual void update()=0;
        virtual void clean()=0;

        virtual void load(const LoaderParams* params) = 0;
    protected:
       GameObject(){}
       
};

#endif /* GAMEOBJECT_H */

