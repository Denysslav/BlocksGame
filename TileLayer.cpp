/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/Game.h"
#include "header/TileLayer.h"
#include "header/Level.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset>& tilesets) 
    : tileSize(tileSize), tilesets(tilesets), position(0., 0.), velocity(0., 0.)
{                
    numColumns = (BlockGame::Instance()->getGameWidth() / tileSize);
    numRows = (BlockGame::Instance()->getGameHeight() / tileSize);
}

void TileLayer::update(Level* level)
{
    render();
}

void TileLayer::render()
{
    int x, y, x2, y2 = 0;
    
    x = position.getX() / tileSize;
    y = position.getY() / tileSize;
    
    x2 = int(position.getX()) % tileSize;
    y2 = int(position.getY()) % tileSize;
    
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            int id = tileIds[i][j + x];
            if (id == 0)
            {
                continue;
            }
            
            Tileset tileset = getTilesetById(id);
            id--;

            
            BlocksTextureManager::Instance()->drawTile(tileset.name,
                                                        2,
                                                        2, 
                                                        (j * tileSize) - x2,
                                                        (i * tileSize) - y2,
                                                        tileSize,
                                                        tileSize,
                                                        (id - (tileset.firstGridId - 1)) / tileset.numColumns,
                                                        (id - (tileset.firstGridId - 1)) % tileset.numColumns,
                                                        BlockGame::Instance()->getRenderer());
        }
    }
    
}

Tileset TileLayer::getTilesetById(int tileId)
{
    for (int i = 0; i < tilesets.size(); i++)
    {
        if (i + 1 <= tilesets.size() - 1)
        {
            if (tileId >= tilesets[i].firstGridId && tileId < tilesets[i + 1].firstGridId)
            {
                return tilesets[i];
            }
        }
        else
        {
            return tilesets[i];
        }
    }
    
    Tileset t;
    
    return t;
}