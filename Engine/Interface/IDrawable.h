//
//  IDrawable.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/25/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IDrawable_h
#define CS587_ShuaiSong_IDrawable_h
#include <SDL2/SDL.h>
#include <assert.h>
#include "Vector2D.h"

class IDrawable
{
   //friend class Actor;
    
protected:
    
    
   // Actor *_owner;

public:
    
    IDrawable(){};

    /**
     *@brief Get the Rectangler of the object;
     *
     */
    
    virtual SDL_Rect GetRect()=0;
    
    /**
     *@brief Set the Rectangler of the object;
     *
     */
    
    virtual void SetRect(SDL_Rect newRect)=0;
    /**
     *@brief set the Poistion of the object;
     *
     */
    
    //virtual void SetPosition(const Vector2D &position)=0;
    
    /**
     *@brief Get the Poistion of the object;
     *
     */
    //virtual const Vector2D& GetPosition()=0;
   
    
    /**
     *@brief Use for draw texture on the screen must be overrided.
     */
    
    virtual void Draw(Vector2D& pos)=0;
    virtual void SetTexture( SDL_Texture * texture)=0;

    virtual ~IDrawable(){}
    
};





#endif
