//
//  ResourceManager.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/28/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__ResourceManager__
#define __CS587_ShuaiSong__ResourceManager__

#include <iostream>
#include "HashMap.h"
#include "JValue.h"
#include "JsonParser.h"
#include  <SDL2/SDL.h>
#include "DebugManager.h"
#include "TextureManager.h"
#include "Sprite.h"
class ResourceManager
{
    
private:
    
    HashMap<JValue*> _jsonMap;
    HashMap<Sprite*> _spriteMap;
    static ResourceManager * _instance;
    ResourceManager(){};
    DynamicArray<JValue*> _metaData;
    
    
public:
    
    static ResourceManager*GetInstance()
    {
        if (_instance == NULL)
        {
            _instance = new ResourceManager();
        }
        return _instance;
    }
    
    Sprite * GetSprite(std::string name);
    void LoadNext();
    JValue*GetJson(std::string name);
    void Load();
    SDL_Texture* GetTexture(std::string name);
    void LoadContent(std::string metadata);
    
//GetImage();
    
};

#endif /* defined(__CS587_ShuaiSong__ResourceManager__) */
