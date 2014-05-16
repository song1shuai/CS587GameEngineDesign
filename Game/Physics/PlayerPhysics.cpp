//
//  PlayerPhysics.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/30/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "PlayerPhysics.h"
void PlayerPhysics::ApplyForce(const Vector2D &force)
{
  _acc.x +=force.x;
  _acc.y +=force.y;
   
}


void PlayerPhysics::Update(float dt)
{
    /*
     TODO: Should add collision detection 
     */

        if (_owner->GetPosition().y+_velocity.y<_ground)
        {
            _owner->GetPosition().y+=_velocity.y;
            
           // DEBUGLOG("%f",_velocity.y);
            _velocity.y+=_gravity;
            isOnGround = false;
            
            
       
           //sceneNode->GetQuadNode()->Update(sceneNode);
            
        }
        else
        {
            _velocity.y=0;
             isOnGround = true;
        }
    

        // DEBUGLOG("%d",a);
    
    
}
Vector2D & PlayerPhysics::GetVelocity()
{
    return _velocity;
}
float & PlayerPhysics::GetOrientation()
{
    return _orientation;
}
void PlayerPhysics::SetVelocity(const Vector2D & veclocity)
{
    _velocity=veclocity;
    
}
void PlayerPhysics::SetSpeed(float speed,const Vector2D &direction)
{
    _velocity.x += speed*direction.x;
    _velocity.y += speed*direction.y;
}