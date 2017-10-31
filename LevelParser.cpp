/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/Game.h"
#include "header/LevelParser.h"
#include "header/TileLayer.h"
#include "tinyxml/tinyxml.h"
#include "header/base64.h"
#include "zlib-1.2.11/zlib.h"
#include "header/GameObjectFactory.h"

Level* LevelParser::parseLevel(const char* levelFile)
{
    TiXmlDocument levelDoc;
    if (!levelDoc.LoadFile(levelFile))
    {
        return NULL;
    }
    
    Level* level = new Level();
    
    TiXmlElement* root = levelDoc.RootElement();
    
    root->Attribute("tilewidth", &tileSize);
    root->Attribute("width", &width);
    root->Attribute("height", &height);
    
    for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("properties"))
        {
            parseTextures(e);
        }
    }
    
    for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("tileset"))
        {
            parseTilesets(e, level->getTilesets());

        }
    }
    
    for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("objectgroup") || e->Value() == std::string("layer"))
        {
            if (e->FirstChildElement()->Value() == std::string("data"))
            {
                parseTileLayer(e, level->getLayers(), level->getTilesets());
            }
        }
    }
    
    return level;
}

void LevelParser::parseTextures(TiXmlElement* textureRoot)
{
    for (TiXmlElement* e = textureRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        BlocksTextureManager::Instance()->load(e->Attribute("value"), 
                                                e->Attribute("name"), 
                                                BlockGame::Instance()->getRenderer());
    }
}

void LevelParser::parseTilesets(TiXmlElement* tilesetRoot, std::vector<Tileset>* tilesets)
{
    BlocksTextureManager::Instance()->load(tilesetRoot->FirstChildElement()->Attribute("source"), tilesetRoot->Attribute("name"), BlockGame::Instance()->getRenderer());
    
    Tileset tileset;
    
    tilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
    tilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
    
    tilesetRoot->Attribute("firstgid", &tileset.firstGridId);
    tilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
    tilesetRoot->Attribute("tileheight", &tileset.tileHeight);
    tilesetRoot->Attribute("spacing", &tileset.spacing);
    tilesetRoot->Attribute("margin", &tileset.margin);
    
    tileset.name = tilesetRoot->Attribute("name");

    tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);
    
    tilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement* tileElement, std::vector<Layer*>* layers, const std::vector<Tileset>* tilesets)
{
    TileLayer* tilelayer = new TileLayer(tileSize, *tilesets);
    
    std::vector<std::vector<int> > data;
    
    std::string decodedIds;
    TiXmlElement* dataNode;

    for (TiXmlElement* e = tileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("data"))
        {
            dataNode = e;
        }
    }
    
    for (TiXmlNode* e = dataNode->FirstChild(); e != NULL; e = e->NextSibling())
    {
        TiXmlText* text = e->ToText();
        std::string t = text->Value();
        decodedIds = base64_decode(t);
    }
    
    uLongf numGids = width * height * sizeof(int);
    std::vector<unsigned> gids(numGids);
    
    uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIds.c_str(), decodedIds.size());
    
    std::vector<int> layerRow(width);
    for (int j = 0; j < height; j++)
    {
        data.push_back(layerRow);
    }
    
    for (int rows = 0; rows < height; rows++)
    {
        for (int cols = 0; cols < width; cols++)
        {
            data[rows][cols] = gids[rows * width + cols];
        }
    }
    
    tilelayer->setTileIds(data);
    layers->push_back(tilelayer);

}