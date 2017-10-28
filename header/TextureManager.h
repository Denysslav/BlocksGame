/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextureManager.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:48 AM
 */

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL2/SDL.h"
#include<string>
#include<map>

class TextureManager
{
    public:
        ~TextureManager();

        bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

        void draw(std::string id,
                  int xPosition,
                  int yPosition,
                  int width,
                  int height,
                  SDL_Renderer* renderer);

        void drawFrame(std::string id,
                       int xPosition,
                       int yPosition,
                       int width,
                       int height,
                       int currentRow,
                       int currentFrame,
                       SDL_Renderer* renderer);

        void clearFromTextureMap(std::string id);

        static TextureManager* Instance()
        {
            if (sInstance == 0)
            {
                sInstance = new TextureManager();
                return sInstance;
            }

            return sInstance;
        }

    private:
        TextureManager(){}

        static TextureManager* sInstance;
        std::map<std::string, SDL_Texture*> textureMap;
};

typedef TextureManager BlocksTextureManager;

#endif /* TEXTUREMANAGER_H */

