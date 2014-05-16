//
//  GameCamera.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "GameCamera.h"
GameCamera::GameCamera()
{
    _target = NULL;
}
Vector2D & GameCamera::GetPosition()
{
   return  _target->GetPosition();
}

