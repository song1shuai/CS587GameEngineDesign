//
//  TextureManager.h
//  sdl
//
//  Created by shuai song on 1/23/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __sdl__TextureManager__
#define __sdl__TextureManager__

#include <iostream>
#include "HashMap.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "SDLRender.h"
#include "DebugManager.h"
class TextureManager
{
    /**
     *@brief This is a Singleton use to load and store Texture
     *
     */

private:
    
    HashMap<SDL_Texture *>      _textureResource;     // Use hashmap to store SDL Texture object.
    static TextureManager *     _instance;            // The TextureManager objet.
    SDL_Renderer*               _render;              // The SDL_Render object.
    
    TextureManager()
    {
        DebugManager::GetInstance()->CreatChannel("Texture");
    
    };

public:
    
    /**
     *@brief a static function used for get the Instance of this singleton
     *
     */
    
    static TextureManager * GetInstance()
    {
       if (_instance==NULL)
            _instance=new TextureManager();
        
      return _instance;
    };
    
    /**
     *@brief Load a texture Into a hashmap.
     *
     *@prama the path of the file
     *@prama the name(key) used for get the object from hashmap
     *@prama the sdl render object used for generate sdl texture obje
     */
    
    bool LoadTexture(std::string filePath,
                     std::string name
                     );
    
    /**
     *@brief Get a Texture object from a name(key);
     *
     *prama The name of texture object
     */
    
   
    SDL_Texture * GetTexture(std::string name);
   
    /**TODO
     * This fuction used for remove a texture object from the hashmap
     * 
     * have not implement yet
     */
    
    void RemoveTexture(std::string name);
    
    
    /*
     * This fuction used for remove a texture object from the hashmap
     *
     * have not implement yet
     */
    
    //void SetSDLRender(SDL_Renderer* render);
    
};



#endif /* defined(__sdl__TextureManager__) */
