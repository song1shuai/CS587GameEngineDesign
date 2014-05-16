//
//  SpriteManager.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/10/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "SpriteManager.h"

Sprite* SpriteManager::GetSprite(std::string name)
{
    if ( !_spriteMap.Find(name))
    {
     return   *_spriteMap.Find(name);
    }
    return NULL;
}
//Sprite* CreateSprite(JValue config,SDL_Texture * spritebatch)
//{

    
//}