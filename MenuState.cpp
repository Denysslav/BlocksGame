/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include "header/Game.h"
#include "header/TextureManager.h"
#include "header/MenuState.h"
#include "header/MenuButton.h"
#include "header/PlayState.h"

//const std::string MenuState::menuId = "MENU";
//
//void MenuState::update()
//{
//    for(std::vector<GameObject*>::size_type i = 0; i != menuObjects.size(); i++)
//    {
//        menuObjects[i]->update();
//    }
//}
//
//void MenuState::render()
//{
//    for(std::vector<GameObject*>::size_type i = 0; i != menuObjects.size(); i++)
//    {
//        menuObjects[i]->draw();
//    } 
//}
//
//bool MenuState::onEnter()
//{
//    if (!BlocksTextureManager::Instance()->load("assets/play.png", "playbutton", BlockGame::Instance()->getRenderer()))
//    {
//        return false;
//    }
//    
//    if (!BlocksTextureManager::Instance()->load("assets/exit.png", "exitbutton", BlockGame::Instance()->getRenderer()))
//    {
//        return false;
//    }
//    
//    GameObject* button1 = new MenuButton(menuToPlay);
//    GameObject* button2 = new MenuButton(exitFromMenu);
//    
//    button1->load(new LoaderParams(230, 190, 180, 48, "playbutton", 1, 0,0));
//    button2->load(new LoaderParams(230, 290, 180, 48, "exitbutton", 1, 0, 0));
//    
//    menuObjects.push_back(button1);
//    menuObjects.push_back(button2);
//
//    return true;
//}
//
//bool MenuState::onExit()
//{
//    for(std::vector<GameObject*>::size_type i = 0; i != menuObjects.size(); i++)
//    {
//        menuObjects[i]->clean();
//    }
//    
////    menuObjects.clear();
//    
//    BlocksTextureManager::Instance()->clearFromTextureMap("playbutton");
//    BlocksTextureManager::Instance()->clearFromTextureMap("exitbutton");
//
//    return true;
//}
//
//void MenuState::menuToPlay()
//{
//    BlockGame::Instance()->getStateMachine()->changeState(new PlayState());
//}
//
//void MenuState::exitFromMenu()
//{
//    BlockGame::Instance()->clean();
//}
