/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/Level.h"

void Level::render()
{
    for (int i = 0; i < layers.size(); i++)
    {
        layers[i]->render();
    }
}

void Level::update()
{
    for (int i = 0; i < layers.size(); i++)
    {
        layers[i]->update(this);
    }
}