/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LoaderParams.h
 * Author: denislav
 *
 * Created on October 25, 2017, 8:47 AM
 */

#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include<string>

class LoaderParams
{
    public:
        LoaderParams(int x, int y, int w, int h, std::string textureId, int numFrames = 0, int callbackId = 0, int animateSpeed = 0);
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        std::string getTextureId() const;

        int getNumFrames() const;
        int getCallbackId() const;
        int getAnimateSpeed() const;
    private:
        int x;
        int y;

        int width;
        int height;

        std::string textureId;
        
        int numFrames;
        int callbackId;
        int animateSpeed;
};

#endif /* LOADERPARAMS_H */

