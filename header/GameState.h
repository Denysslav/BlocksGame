/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameState.h
 * Author: denislav
 *
 * Created on October 25, 2017, 10:39 AM
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<string>
#include<vector>

class GameState
{
    public:
        virtual void update() = 0;
        virtual void render() = 0;
        virtual bool onEnter() = 0;
        virtual bool onExit() = 0;
        virtual std::string getStateId() const = 0;
    protected:
        std::vector<std::string> textureIdList;
};

#endif /* GAMESTATE_H */

