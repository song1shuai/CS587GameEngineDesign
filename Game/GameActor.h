//
//  GameActor.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/1/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__GameActor__
#define __CS587_ShuaiSong__GameActor__

#include <iostream>
#include "Actor.h"
#include "Drawable.h"
#include "PlayerPhysics.h"
#include "IState.h"
#include "DynamicArray.h"
#include "Sprite.h"
#include "ActorData.h"
#include "UtilityFuc.h"
class GameActor:public Actor
{
private:
    
    Vector2D _center;
    
public:
    ActorData data;
    Vector2D JumpSpeed;
    Vector2D RunSpeed;
    
    ICollider * GetCollider();
    
    GameActor();
    ~GameActor();
    
   const Vector2D& GetCenter();
    
    
    
    
    
    
};
#endif /* defined(__CS587_ShuaiSong__GameActor__) */
