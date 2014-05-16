//
//  Actor.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Actor.h"
Actor::Actor ()
{
    //_drawable=new Drawable();
    //_physics= new BasicPhysics(PhysicsArgu::basicArgu);
 
    _drawable=NULL;
    _physics=NULL;
    _collider=NULL;
    _ID=GetUniqueID();
    _position = Vector2D::ZERO;
   // _isCollidable =  true;
}
Actor::~Actor()
{

}

IDrawable * Actor::GetDrawable()
{
    return  _drawable;
}
IPhysics * Actor::GetPhysics()
{
    return _physics;
}

void Actor::SetPhysics(IPhysics*  physics)
{
    assert(physics!=NULL);
    

    _physics=physics;
    
}
void Actor::SetDrawable(IDrawable* drawable)
{
    assert(drawable!=NULL);
    
  
    _drawable=drawable;
    
}
int Actor::GetID()
{
    return _ID;
}
void Actor::SetPosition(const Vector2D &position)
{
    this->_position = position;
}

Vector2D& Actor::GetPosition()
{
    
    return _position;
}

ICollider *  Actor::GetCollider()
{
    return _collider;
}
void  Actor::SetCollider(ICollider * collider)
{
    _collider = collider;
}

