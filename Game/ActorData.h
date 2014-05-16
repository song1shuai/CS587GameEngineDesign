//
//  ActorData.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/11/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__ActorData__
#define __CS587_ShuaiSong__ActorData__

#include <iostream>
#include "Vector2D.h"
#include  <string>
class ActorData
{
    public:
            int jumpSpeed;
            int maxJumpSpeed;
            std::string asset;
            float acceleration;
            Vector2D direction;
            Vector2D position;
};

#endif /* defined(__CS587_ShuaiSong__ActorData__) */
