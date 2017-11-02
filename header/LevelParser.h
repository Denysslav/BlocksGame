/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelParser.h
 * Author: denislav
 *
 * Created on October 29, 2017, 12:40 AM
 */

#ifndef LEVELPARSER_H
#define LEVELPARSER_H

#include<vector>
#include "Level.h"
#include "../tinyxml/tinyxml.h"

class LevelParser
{
public:
    Level* parseLevel(const char* levelFile);
private:
    void parseTextures(TiXmlElement* textureRoot);
    void parseTilesets(TiXmlElement* tilesetRoot, std::vector<Tileset>* tilesets);
    int parseTileLayer(TiXmlElement* tileElement,  std::vector<Layer*> *layers, const std::vector<Tileset>* tilesets);
    void parseObjectLayer(TiXmlElement* objectElement, std::vector<Layer*> *layers, Level* level);
    
    int tileSize;
    int width;
    int height;
};

#endif /* LEVELPARSER_H */

