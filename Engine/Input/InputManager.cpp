//
//  InputManager.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/16/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "InputManager.h"
InputManager * InputManager::_instance=NULL;
InputManager::InputManager()
{
  _keyState = SDL_GetKeyboardState(NULL);
    
}
InputManager::~InputManager()
{

    
}
bool InputManager::KeyPressed(SDL_Scancode key)
{
    if (_keyState!=0)
    {
        return _keyState[key]==1;
    }
    
    return false;
}

void InputManager::Update()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {
            HandleOnKeyDown(e.key.keysym.scancode);
        }
        if (e.type == SDL_KEYUP)
        {
            HandleOnkeyUp(e.key.keysym.scancode);
        }
  
        
    }
}
bool InputManager::KeyReleased(SDL_Scancode key)
{

    
    if( _e.type == SDL_KEYDOWN && _e.key.keysym.sym == key )
	{
		return true;
	}
    return false;
}

void InputManager::AddKeyboardListener(IKeyboardListener *listerner)
{
    
    _keyboardListenerList.InsertAtLast(listerner);
}
void InputManager::RemoveKeyboardListener (IKeyboardListener * listerner)
{

    _keyboardListenerList.Remove(listerner);
}
void InputManager::HandleOnKeyDown(int key)
{
    for (int i = 0; i < _keyboardListenerList.GetLength(); i++)
    {
        _keyboardListenerList[i]->OnKeyDown( key);
    }
}
void InputManager::HandleOnkeyUp(int key)
{
    for (int i = 0; i < _keyboardListenerList.GetLength(); i++)
    {
        _keyboardListenerList[i]->OnKeyUp(key);
    }
}