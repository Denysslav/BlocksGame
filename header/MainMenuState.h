/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenuState.h
 * Author: denislav
 *
 * Created on October 28, 2017, 12:24 AM
 */

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include<vector>
#include "GameObject.h"
#include "MenuState.h"

class MainMenuState : public MenuState
{
    public:
        virtual void update();
        virtual void render();
        
        virtual bool onEnter();
        virtual bool onExit();
        
        virtual std::string getStateId() const;
        
        private:
            std::vector<GameObject*> gameObjects;
            
            virtual void setCallbacks(const std::vector<Callback>& callbacks);
            
            static void menuToPlay();
            static void exitFromMenu();
            
            static const std::string menuId; 
};


#endif /* MAINMENUSTATE_H */

