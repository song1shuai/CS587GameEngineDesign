//
//  SpriteManager.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/10/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__SpriteManager__
#define __CS587_ShuaiSong__SpriteManager__

#include <iostream>
#include "HashMap.h"
#include "Sprite.h"
#include "JValue.h"
#include <SDL2/SDL.h>
class SpriteManager
{
private:
    HashMap<Sprite*> _spriteMap;
public:
    SpriteManager();
    Sprite* GetSprite(std::string name);
    //Sprite* CreateSprite(JValue config,SDL_Texture * spritebatch);
    
};
#endif /* defined(__CS587_ShuaiSong__SpriteManager__) */
