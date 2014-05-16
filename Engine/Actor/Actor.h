//
//  Actor.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//88

#ifndef __CS587_ShuaiSong__Actor__
#define __CS587_ShuaiSong__Actor__

#include <iostream>
#include "Vector2D.h"
#include "UtilityFuc.h"
#include "IDrawable.h"
#include "IPhysics.h"
#include "ICollider.h"
class IPhysics;
class IDrawable;

class Actor
{
private:
    
    int _ID;                   //The unique ID of current actor
   
protected:
    Vector2D         _position;
    IPhysics *       _physics;    //The Iphysics  component
    IDrawable*       _drawable;   //The IDrawable component
    ICollider*       _collider;   //The collider component
    
public:
    
    Actor ();
    void Init();
    //Actor(SDL_Texture *texture,int x,int y);
    
    /**
     *@brief Get the IDrawable components
     *
     */
    
    virtual IDrawable* GetDrawable();
    
    /**
     *@brief Get the IPhysics components
     *
     */
    
    virtual IPhysics* GetPhysics();
    
    /**
     *@brief Set the IPhysics components
     *
     */
    
    void SetPhysics(IPhysics*  physics);
    
    /**
     *@brief Set the IDrawable components
     *
     */
    
    
    void SetDrawable(IDrawable* drawable);
    
    virtual ICollider * GetCollider();
    void SetCollider(ICollider * collider);
    virtual ~Actor();
    int GetID();
    
    Vector2D& GetPosition();
    void SetPosition(const Vector2D &position);
    
};

#endif /* defined(__CS587_ShuaiSong__Actor__) */
