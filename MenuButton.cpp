/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/MenuButton.h"
#include "header/InputHandler.h"

MenuButton::MenuButton() : SDLGameObject()
{
}

void MenuButton::load(const LoaderParams* params)
{
    SDLGameObject::load(params);
    callbackId = params->getCallbackId();
    currentFrame = MOUSE_OUT;
}

void MenuButton::draw()
{
    SDLGameObject::draw();
}

void MenuButton::update()
{
    Vector2D* mousePosition = BlockInputHandler::Instance()->getMousePosition();
    
    if (mousePosition->getX() < (position.getX() + width)
        && mousePosition->getX() > position.getX()
        && mousePosition->getY() < (position.getY() + height)
        && mousePosition->getY() > position.getY())
    {
        currentFrame = MOUSE_OVER;
        if (BlockInputHandler::Instance()->getMouseButtonState(BlockInputHandler::LEFT)
                && released)
        {
            currentFrame = CLICKED;
            
            callback();
            
            released = false;
        }
        else if (!BlockInputHandler::Instance()->getMouseButtonState(BlockInputHandler::LEFT))
        {
            released = true;
            currentFrame = MOUSE_OVER;
        }
        else
        {
            currentFrame = MOUSE_OUT;
        }
    }
    else 
    {
        currentFrame = MOUSE_OUT;
    }
    
}

void MenuButton::clean()
{
    SDLGameObject::clean();
}