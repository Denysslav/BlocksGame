/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Layer.h
 * Author: denislav
 *
 * Created on October 29, 2017, 12:10 AM
 */

#ifndef LAYER_H
#define LAYER_H

class Level;

class Layer
{
public:
    virtual void render() = 0;
    virtual void update(Level* level) = 0;
protected:
    ~Layer(){};
};

#endif /* LAYER_H */

