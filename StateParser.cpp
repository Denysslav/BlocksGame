/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/Game.h"
#include "header/GameObjectFactory.h"
#include "header/StateParser.h"
#include "tinyxml/tinyxml.h"

bool StateParser::parseState(const char* stateFile, std::string stateId, std::vector<GameObject*>* objects, std::vector<std::string> *textureIds)
{
    TiXmlDocument xmlDoc;
    
    if (!xmlDoc.LoadFile(stateFile))
    {
        return false;
    }
    
    TiXmlElement* root = xmlDoc.RootElement();
    TiXmlElement* stateRoot = 0;
    
    for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if (e->Value() == stateId)
        {
            stateRoot = e;
        }
    }
    
    TiXmlElement* textureRoot = 0;
    for (TiXmlElement* e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("textures"))
        {
            textureRoot = e;
        }
    }
    
    parseTextures(textureRoot, textureIds);
    
    TiXmlElement* objectRoot = 0;
    for (TiXmlElement* e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("objects"))
        {
            objectRoot = e;
        }
    }
    
    parseObjects(objectRoot, objects);
    
    return true;
}

void StateParser::parseTextures(TiXmlElement* stateRoot, std::vector<std::string> *textureIds)
{
    for (TiXmlElement* e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        std::string filenameAttr = e->Attribute("filename");
        std::string idAttr = e->Attribute("id");
        textureIds->push_back(idAttr);
        
        BlocksTextureManager::Instance()->load(filenameAttr, idAttr, BlockGame::Instance()->getRenderer());
    }
}

void StateParser::parseObjects(TiXmlElement* stateRoot, std::vector<GameObject*> *objects)
{
    for (TiXmlElement* e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {
        int x, y, w, h, numFrames, callbackId, animateSpeed;
        std::string textureId;
        
        e->Attribute("x", &x);
        e->Attribute("y", &y);
        e->Attribute("width", &w);
        e->Attribute("height", &h);
        e->Attribute("numFrames", &numFrames);
        e->Attribute("callbackId", &callbackId);
        e->Attribute("animateSpeed", &animateSpeed);
        
        textureId = e->Attribute("textureId");
        
        GameObject* gameObject = BlockGameObjectFactory::Instance()->create(e->Attribute("type"));
        gameObject->load(new LoaderParams(x, y, w, h, textureId, numFrames, callbackId, animateSpeed));
        
        objects->push_back(gameObject);
    }
}
