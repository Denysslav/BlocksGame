/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "header/InputHandler.h"
#include "header/Level.h"
#include "header/ObjectLayer.h"
#include "header/Player.h"
#include "header/Ball.h"

void ObjectLayer::update(Level* level)
{
    collisionManager.checkBallBrickCollision(level->getBall(), level->getCollidableLayers());

    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (BlockInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
        {
            if (dynamic_cast<Player*>(gameObjects[i]))
            {
                Player* p = dynamic_cast<Player*>(gameObjects[i]);
                if (!p->getGameBegin())
                {
                    p->setGameBegin(true);
                }
            }
            
            if (dynamic_cast<Ball*>(gameObjects[i]))
            {
                Ball* p = dynamic_cast<Ball*>(gameObjects[i]);
                if (!p->getGameBegin())
                {
                    p->setGameBegin(true);
                }
            }
        }
        gameObjects[i]->update();
    }
}

void ObjectLayer::render()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

