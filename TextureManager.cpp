/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/TextureManager.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

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

void TextureManager::drawTile(std::string id, 
                             int margin, 
                             int spacing, 
                             int x, 
                             int y, 
                             int width, 
                             int height, 
                             int currentRow, 
                             int currentFrame, 
                             SDL_Renderer* renderer)
{

    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = margin + (spacing + width) * currentFrame;
    srcRect.y = margin + (spacing + height) * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}

void TextureManager::drawText(int x, int y, char* content, SDL_Rect* rect, SDL_Renderer* renderer)
{
    
    TTF_Font* ttfFont = TTF_OpenFont("font/OpenSans.ttf", 24);
    SDL_Color white = {255,255,255};
    
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(ttfFont, content, white);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    rect->x = x;
    rect->y = y;
    rect->w = surfaceMessage->w;
    rect->h = surfaceMessage->h;
    
    SDL_FreeSurface(surfaceMessage);
    SDL_RenderCopy(renderer, message, NULL, rect);
    SDL_DestroyTexture(message);
    TTF_CloseFont(ttfFont);
}

void TextureManager::clearFromTextureMap(std::string id)
{
    textureMap.erase(id);
}