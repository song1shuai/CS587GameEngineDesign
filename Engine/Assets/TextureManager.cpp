//
//  TextureManager.cpp
//  sdl
//
//  Created by shuai song on 1/23/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "TextureManager.h"

TextureManager * TextureManager::_instance = NULL;

bool TextureManager::LoadTexture(std::string filePath,std::string name)
{
    //Load image by path
    
    SDL_Surface * surface = IMG_Load(filePath.c_str());
    
    if (surface == NULL)
    {
        //std::cout<<"texture can not load!!";
        DEBUGCLOG("Texture","%s%s",name.c_str()," can not load!!!" );
        return false;
    }
    
    //Create a SDL_texture structure
    
    SDL_Texture * texture =SDL_CreateTextureFromSurface(SDLRender::render, surface);
    SDL_free(surface);
    
    if (texture==NULL)
    {
        std::cout<<"texture "<<name<<"can not be created!!";
        return false;
    }
    
    //Insert SDL_texture structure into hashmap
    
    _textureResource.Insert(name,texture);
    
    return true;
    
}

SDL_Texture * TextureManager::GetTexture(std::string name)
{
    SDL_Texture ** texture=_textureResource.Find(name);
    
    assert(texture!=NULL);
    
    return * _textureResource.Find(name);
}

void TextureManager::RemoveTexture(std::string name)
{
    
    
}
//void TextureManager::SetSDLRender(SDL_Renderer* render)
//{
//    _render=render;
//}