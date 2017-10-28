/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuButton.h
 * Author: denislav
 *
 * Created on October 25, 2017, 1:01 PM
 */

#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "SDLGameObject.h"
#include "BaseCreator.h"

class MenuButton : public SDLGameObject
{
    public:
        MenuButton();
        
        virtual void draw();
        virtual void update();
        virtual void clean();
   
        virtual void load(const LoaderParams* params);
        
        void setCallback(void(*cb)())
        {
            callback = cb;
        }
        
        int getCallbackId()
        {
            return callbackId;
        }
        
        enum buttonState
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };
      
    private:
        int callbackId;
        bool released;
        void (*callback)();
};

class MenuButtonCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new MenuButton();
    }
};
#endif /* MENUBUTTON_H */

