/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header/Game.h"
#include "header/TextureManager.h"
#include "header/InputHandler.h"
#include "header/GameStateMachine.h"
#include "header/GameObjectFactory.h"
#include "header/MainMenuState.h"
#include "header/PlayState.h"
#include "header/MenuButton.h"
#include "header/Player.h"
#include "header/Ball.h"
#include "header/AnimatedGraphic.h"

Game* Game::sInstance = 0;

void Game::init(const char* title, int xPosition, int yPosition, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        blocksWindow = SDL_CreateWindow(title,
                                        xPosition,
                                        yPosition,
                                        width,
                                        height,
                                        flags);
        if (blocksWindow != 0)
        {
            blocksRenderer = SDL_CreateRenderer(blocksWindow, -1, 0);
            if (blocksRenderer != 0)
            {
                SDL_SetRenderDrawColor(blocksRenderer, 0, 0, 0, 255);
                
                BlockGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
                BlockGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
                BlockGameObjectFactory::Instance()->registerType("Ball", new BallCreator());
                BlockGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
                
                gameStateMachine = new GameStateMachine();
                gameStateMachine->pushState(new MainMenuState());
            }
        }
    }

    isRunning = true;
}

void Game::render()
{
    SDL_RenderClear(blocksRenderer);

    gameStateMachine->render();

    SDL_RenderPresent(blocksRenderer);
}

void Game::handleEvents()
{
    BlockInputHandler::Instance()->update();
    if (BlockInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        GameState* currentState = gameStateMachine->getCurrentState();
        if (currentState->getStateId() == "play")
        {
            PlayState* ps = dynamic_cast<PlayState*>(currentState);
            ps->startMoving(true);
        }
    }
}

void Game::update()
{
    gameStateMachine->update();
}

void Game::clean()
{
    BlockInputHandler::Instance()->clean();

    SDL_DestroyWindow(blocksWindow);
    SDL_DestroyRenderer(blocksRenderer);
    SDL_Quit();
    
    isRunning = false;
}

SDL_Renderer* Game::getRenderer() const
{
    return blocksRenderer;
}

GameStateMachine* Game::getStateMachine()
{
    return gameStateMachine;
}