/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TileLayer.h
 * Author: denislav
 *
 * Created on October 29, 2017, 12:34 AM
 */

#ifndef TILELAYER_H
#define TILELAYER_H

#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"

class TileLayer : public Layer
{
    public:

        TileLayer(int tileSize, const std::vector<Tileset> &tilesets);

        virtual void update(Level* level);
        virtual void render();

        void setTileIds(const std::vector<std::vector<int> > &data)
        {
            tileIds = data;
        }

        int getTileSize()
        {
            return tileSize;
        }
        
        void setTileSize(int ts)
        {
            tileSize = ts;
        }

        Tileset getTilesetById(int tileId);
        
        std::vector<std::vector<int> > getTileIds()
        {
            return tileIds;
        }
        
        Vector2D getPosition()
        {
            return position;
        }
        
    private:
        int numColumns;
        int numRows;
        int tileSize;
        
        Vector2D position;
        Vector2D velocity;
        
        const std::vector<Tileset> &tilesets;
        std::vector<std::vector<int> > tileIds;
};


#endif /* TILELAYER_H */

