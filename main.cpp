/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: denislav
 *
 * Created on October 25, 2017, 8:42 AM
 */

#include <stdlib.h>
#include "header/Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main ( int argc, char** argv )
{
    Uint32 frameStart, frameTime;

    BlockGame::Instance()->init("Blocks Game", 100, 100, 640, 480, 0);
    while (BlockGame::Instance()->running())
    {
        frameStart = SDL_GetTicks();

        BlockGame::Instance()->handleEvents();
        BlockGame::Instance()->update();
        BlockGame::Instance()->render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
        {
            SDL_Delay((int) DELAY_TIME - frameTime);
        }
    }
    

    BlockGame::Instance()->clean();
    
    return 0;
}

