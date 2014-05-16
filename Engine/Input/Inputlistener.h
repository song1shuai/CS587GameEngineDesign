//
//  Inputlistener.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/17/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_Inputlistener_h
#define CS587_ShuaiSong_Inputlistener_h
#include <SDL2/SDL.h>
#include "HashMap.h"
class IKeyboardListener
{
public:
    
    virtual void OnKeyDown(int key)=0;
    virtual void OnKeyUp(int key)=0;
    
    
};
#endif
