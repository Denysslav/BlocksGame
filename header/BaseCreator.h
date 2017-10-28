/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseCreator.h
 * Author: denislav
 *
 * Created on October 27, 2017, 12:07 AM
 */

#ifndef BASECREATOR_H
#define BASECREATOR_H

#include "GameObject.h"

class BaseCreator
{
public:
    virtual GameObject* createGameObject() const = 0;
    virtual ~BaseCreator(){}
};


#endif /* BASECREATOR_H */

