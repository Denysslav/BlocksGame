/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateParser.h
 * Author: denislav
 *
 * Created on October 27, 2017, 8:16 PM
 */

#ifndef STATEPARSER_H
#define STATEPARSER_H

#include<iostream>
#include<vector>
#include"../tinyxml/tinyxml.h"

class GameObject;

class StateParser
{
public:
    bool parseState(const char* stateFile, std::string stateId, std::vector<GameObject*>* objects, std::vector<std::string> *textureIds);
private:
    void parseObjects(TiXmlElement* stateRoot, std::vector<GameObject*> *objects);
    void parseTextures(TiXmlElement* stateRoot, std::vector<std::string> *textureIds);
};

#endif /* STATEPARSER_H */

