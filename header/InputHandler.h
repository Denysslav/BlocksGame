/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputHandler.h
 * Author: denislav
 *
 * Created on October 25, 2017, 10:37 AM
 */

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include<vector>
#include "Vector2D.h"
#include "SDL2/SDL.h"

class InputHandler
{
    public:
       static InputHandler* Instance()
        {
            if (sInstance == 0)
            {
                sInstance = new InputHandler();
            }

            return sInstance;
        }


        void onMouseMove(SDL_Event& event);
        void onMouseButtonDown(SDL_Event& event);
        void onMouseButtonUp(SDL_Event& event);
        
        bool isKeyDown(SDL_Scancode key);
        void onKeyDown();
        void onKeyUp();
        
        void update();
        void clean();

        Vector2D* getMousePosition();
        bool getMouseButtonState(int buttonNumber);

        enum mouseButtons
        {
            LEFT = 0,
            MIDDLE = 1,
            RIGHT = 2
        };

    private:
        InputHandler()
        {
            mousePosition = new Vector2D(0., 0.);
            
             for (int i = 0; i < 3; i++)
            {
                mouseButtonStates.push_back(false);
            }
        }

        ~InputHandler(){}

        static InputHandler* sInstance;

        Vector2D* mousePosition;
        std::vector<bool> mouseButtonStates;
        
        const Uint8* keystates;
};

typedef InputHandler BlockInputHandler;

#endif /* INPUTHANDLER_H */

