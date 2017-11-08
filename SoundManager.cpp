/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/SoundManager.h"

SoundManager* SoundManager::sInstance = 0;

SoundManager::SoundManager()
{
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) != 0)
    {
        std::cout << "Could not init mixer" << std::endl;
    }
}

SoundManager::~SoundManager()
{
    Mix_CloseAudio();
}

bool SoundManager::load(std::string fileName, std::string soundId)
{
    fileName = "sound/" + fileName;
    Mix_Chunk* chunk = Mix_LoadWAV(fileName.c_str());
    if (chunk == 0)
    {
        std::cout << "Could not load sound: " << Mix_GetError() << std::endl;
        return false;
    }
    
    sounds[soundId] = chunk;
}

void SoundManager::playSound(std::string soundId, int loop)
{
    Mix_PlayChannel(-1, sounds[soundId], loop);
}

void SoundManager::clearSoundMap()
{
//    for (int i = sounds.begin(); i != sounds.end(); i++)
//    {
//        Mix_FreeChunk(i->second);
//    }
    
    sounds.clear();
}