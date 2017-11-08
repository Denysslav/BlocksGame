/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SoundManager.h
 * Author: denislav
 *
 * Created on November 6, 2017, 11:50 AM
 */

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include<iostream>
#include <string>
#include<map>

#include "SDL2/SDL_mixer.h"

class SoundManager
{
public:
    static SoundManager* Instance()
    {
        if (sInstance == 0)
        {
            sInstance = new SoundManager();
        }
        
        return sInstance;
    }
    
    bool load(std::string fileName, std::string soundId);
    void playSound(std::string soundId, int loop);
    void clearSoundMap();
    
private:
    static SoundManager* sInstance;
    
    std::map<std::string, Mix_Chunk*> sounds;
    
    SoundManager();
    ~SoundManager();
};

typedef SoundManager BlockSoundManager;

#endif /* SOUNDMANAGER_H */

