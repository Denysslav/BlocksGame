/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/CollisionManager.h"
#include "header/SDLGameObject.h"
#include "header/TileLayer.h"

void CollisionManager::checkBallBrickCollision(Ball* ball, const std::vector<Layer*>& tileLayers)
{
    if (!ball->getGameBegin())
    {
        return;
    }
    
    for (int i = 0; i < tileLayers.size(); i++)
    {

        TileLayer* tileLayer;
        if (!dynamic_cast<TileLayer*>(tileLayers[i]))
        {
            continue;
        }
        
        tileLayer = dynamic_cast<TileLayer*>(tileLayers[i]);

        std::vector<std::vector<int> > tiles = tileLayer->getTileIds();

        Vector2D layerPos = tileLayer->getPosition();
        
        int x, y, tileColumn, tileRow, tileId = 0;

        x = layerPos.getX() / tileLayer->getTileSize();
        y = layerPos.getY() / tileLayer->getTileSize();

        if (ball->getVelocity().getX() >= 0 || ball->getVelocity().getY() >= 0)
        {
            tileColumn = ((ball->getPosition().getX() + ball->getWidth()) / tileLayer->getTileSize());
            tileRow = ((ball->getPosition().getY() + ball->getHeight()) / tileLayer->getTileSize());
            tileId = tiles[tileRow + y][tileColumn + x];
        }
        else if (ball->getVelocity().getX() < 0 || ball->getVelocity().getY() < 0)
        {
            tileColumn = ball->getPosition().getX() / tileLayer->getTileSize();
            tileRow = ball->getPosition().getY() / tileLayer->getTileSize();
            tileId = tiles[tileRow + y][tileColumn + x];
        }
        
        if (tileId != 0)
        {
            tiles[tileRow + y][tileColumn + x] = 0;
            tileLayer->setTileIds(tiles);
        }
    }
}