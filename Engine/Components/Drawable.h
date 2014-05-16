//
//  Drawable.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__Drawable__
#define __CS587_ShuaiSong__Drawable__
#include <iostream>
#include <SDL2/SDL.h>
#include <assert.h>
#include "SDLRender.h"
#include "IDrawable.h"
#include "TextureManager.h"
class Drawable:public IDrawable
{
    
    
private:
    
     SDL_Texture *   _texture;   //The Texture of the object
     SDL_Rect        _objRect;   //The Rectangle structure of the image
    //Vector2D        _position;
    int _width;
    int _height;
    
   // SceneNode& _sceneNode;
public:
    Drawable();
   // Drawable(SceneNode &sceneNode);
    Drawable(SDL_Texture *texture);
    
    Drawable(std::string name);
    
    virtual ~Drawable();
    
    /**
     *@brief Overide function from idrawable.
     *
     */
    
    virtual void Draw(Vector2D& pos);
    
    
    /**
     *@brief Get the Rectangler of the object;
     *
     */
    
    SDL_Rect GetRect();
    void SetRect(SDL_Rect newRect);
    
    /**
     *@brief set the x coordinate of the rectangler
     *
     *prama the x value
     */
    
    void SetWidth(int width);
    
    /**
     *@brief set the y coordinate of the rectangler
     *
     *prama the y value
     */
    
    void SetHeight(int height);
    
    /**
     *@brief get the X coordinate of the rectangler.
     *
     */
    
    int GetWidth();
    
    /**
     *@brief get the y coordinate of the rectangler.
     *
     */
    
    int GetY();
    
    /**
     *@brief Set the x,y coordinate of the rectangler
     *
     *prama the x value
     *prama the y value
     */
    
    //void SetPosition(const Vector2D &position);
    
    
    /**
     *@brief Set the texture
     *
     *prama the SDL_texture reference
     */
    
    void SetTexture( SDL_Texture * texture);
    
   // const Vector2D& GetPosition();
    
};
#endif /* defined(__CS587_ShuaiSong__Drawable__) */
