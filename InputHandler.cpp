   /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/InputHandler.h"
#include "header/Game.h"

InputHandler* InputHandler::sInstance = 0;

void InputHandler::update()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        keystates = SDL_GetKeyboardState(NULL);
        
        switch(event.type)
        {
            case SDL_QUIT:
                BlockGame::Instance()->clean();
                break;
            case SDL_KEYDOWN:
                onKeyDown();
                break;
            case SDL_KEYUP:
                onKeyUp();
                break;
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
            default:
                break;
        }
        
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (keystates != 0)
    {
        if (keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    return false;
}

void InputHandler::onKeyDown()
{
    
}

void InputHandler::onKeyUp()
{
    
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {     
        mouseButtonStates[LEFT] = true;
    }

    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = true;
    }

    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = true;
    }

}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
    {
        mouseButtonStates[LEFT] = false;
    }

    if (event.button.button == SDL_BUTTON_MIDDLE)
    {
        mouseButtonStates[MIDDLE] = false;
    }

    if (event.button.button == SDL_BUTTON_RIGHT)
    {
        mouseButtonStates[RIGHT] = false;
    }
}

void InputHandler::onMouseMove(SDL_Event& event)
{
     mousePosition->setX(event.motion.x);
     mousePosition->setY(event.motion.y);
}

void InputHandler::clean()
{

}

Vector2D* InputHandler::getMousePosition()
{
    return mousePosition;
}

bool InputHandler::getMouseButtonState(int button)
{
    return mouseButtonStates[button];
}
