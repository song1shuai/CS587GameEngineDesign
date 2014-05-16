//
//  IPhysics.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/25/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IPhysics_h
#define CS587_ShuaiSong_IPhysics_h
//#include <SDL2/SDL.h>
#include "Vector2D.h"
#include "DynamicArray.h"
#include "ISceneNode.h"
#include "Actor.h"

class IPhysics
{
protected:
public:
    
    bool isOnGround;
    float speed;
    float acceleration;
    Vector2D direction;
    Actor * _owner;
    
    IPhysics(Actor * owenr):_owner(owenr)
    {
        isOnGround=false;
    };
    ISceneNode * sceneNode;
    virtual ~IPhysics(){};
    virtual void Update(float dt)=0;
    virtual void ApplyForce(const Vector2D & )=0;
    virtual Vector2D & GetVelocity()=0;
    virtual void SetVelocity(const Vector2D & veclocity)=0;
    virtual void SetSpeed(float speed,const Vector2D &direction)=0;
    virtual float & GetOrientation()=0;

};

#endif
