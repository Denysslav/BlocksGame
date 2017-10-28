/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuState.h
 * Author: denislav
 *
 * Created on October 25, 2017, 10:40 AM
 */

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <vector>
#include"GameState.h"
#include "GameObject.h"

class MenuState : public GameState
{
    protected:
        typedef void(*Callback)();
        virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
        
        std::vector<Callback> callbacks;
};

#endif /* MENUSTATE_H */

