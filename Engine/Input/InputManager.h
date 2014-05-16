//
//  InputManager.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/16/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__InputManager__
#define __CS587_ShuaiSong__InputManager__

#include <iostream>
#include "DynamicArray.h"
#include <SDL2/SDL.h>
#include "Inputlistener.h"

typedef DynamicArray<IKeyboardListener *> KEYBOARDLIST ;
class InputManager
{
private:
    
    
    SDL_Event               _e ;                    //The event from sdl event pool
    const Uint8*            _keyState;              //The keyboard state
    static InputManager *   _instance;              // the instance use for access this class.
    KEYBOARDLIST            _keyboardListenerList;
    
    InputManager();                                 // keep this class as the sington.
    
public:
    
    static InputManager * GetInstance()
    {
        if (_instance == NULL)
        {
             _instance= new InputManager();
            return _instance;
        }
        return _instance;
    }
    
    ~InputManager();
    void Update();                                                  // pool the event from the sdl event quere
    bool KeyPressed(SDL_Scancode key);                              // check if the key is is pressed
    bool KeyReleased(SDL_Scancode key);                             // check if the key is is released
    void AddKeyboardListener(IKeyboardListener * listerner);        // add keyboard to he
    void RemoveKeyboardListener (IKeyboardListener * listerner);    // remove the keyboard listner from the listnner list
    void HandleOnKeyDown(int key);                                  // Send the pressd key to the listner
    void HandleOnkeyUp(int key);                                    // send the released key to the listner
    
};
#endif /* defined(__CS587_ShuaiSong__InputManager__) */
