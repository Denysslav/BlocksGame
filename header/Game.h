/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:45 AM
 */

#ifndef GAME_H
#define GAME_H

#include<vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "GameStateMachine.h"
#include "SoundManager.h"

class Game
{
    public:
        ~Game();

        void init(const char* title, int xPosition, int yPosition, int width, int height, int flags);
        void render();
        void update();
        void handleEvents();
        void clean();
        SDL_Renderer* getRenderer() const;

        bool running()
        {
            return isRunning;
        }

        int getGameWidth() const
        {
            return gameWidth;
        }
        
        int getGameHeight() const
        {
            return gameHeight;
        }
        
        GameStateMachine* getStateMachine();
        
        static Game* Instance()
        {
            if (sInstance == 0)
            {
                sInstance = new Game();
                return sInstance;
            }

            return sInstance;
        }

    private:
        Game(){}

        static Game* sInstance;

        SDL_Window* blocksWindow;
        SDL_Renderer* blocksRenderer;

        std::vector<GameObject*> gameObjects;
        
        GameStateMachine* gameStateMachine;
        
        int currentFrame;
        int gameWidth;
        int gameHeight;
        
        bool isRunning;
};

typedef Game BlockGame;

#endif /* GAME_H */

