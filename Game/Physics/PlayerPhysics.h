//
//  PlayerPhysics.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/30/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__PlayerPhysics__
#define __CS587_ShuaiSong__PlayerPhysics__

#include <iostream>
#include "IPhysics.h"
#include "BitArray.h"
#include "GameActor.h"
#include "Engine.h"

class PlayerPhysics:public IPhysics
{
private:
    
    Vector2D _velocity;
    Vector2D _acc;
    float _gravity;
    float _orientation;
    Vector2D _moveSpeed;
    Vector2D _jumpSpeed;
    float _ground;
    

public:
    PlayerPhysics(Actor * owner):IPhysics(owner),
    _velocity(Vector2D::ZERO),
    _orientation(0.0f)
    {
        /*
         TODO:
         Should be data driven
         */
        
        _gravity = 0.3;
        _ground = 280;
    }
    
    void Update(float dt);
    void ApplyForce(const Vector2D &force);
    Vector2D & GetVelocity();
    float & GetOrientation();
    void SetVelocity(const Vector2D & veclocity);
    void SetSpeed(float speed,const Vector2D &direction);
    

    
};

#endif /* defined(__CS587_ShuaiSong__PlayerPhysics__) */
