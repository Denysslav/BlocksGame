/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/TextureManager.h"
#include "SDL2/SDL_image.h"

TextureManager* TextureManager::sInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());

    if (tempSurface == 0)
    {
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (texture != 0)
    {
        textureMap[id] = texture;
        return true;
    }

    return false;
}

void TextureManager::draw(std::string id,
                          int xPosition,
                          int yPosition,
                          int width,
                          int heigth,
                          SDL_Renderer* renderer)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = heigth;

    destRect.x = xPosition;
    destRect.y = yPosition;

    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}

void TextureManager::drawFrame(std::string id,
                                int xPosition,
                                int yPosition,
                                int width,
                                int height,
                                int cR,
                                int cF,
                                SDL_Renderer* renderer)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * cF;
    srcRect.y = height * (cR - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = xPosition;
    destRect.y = yPosition;

    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}

void TextureManager::clearFromTextureMap(std::string id)
{
    textureMap.erase(id);
}