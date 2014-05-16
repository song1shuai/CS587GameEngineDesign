//
//  GameCamera.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__GameCamera__
#define __CS587_ShuaiSong__GameCamera__

#include <iostream>
#include "ICamera.h"
#include "GameActor.h"
class GameCamera:public ICamera
{
private:
    GameActor * _target;        //Target of the camere focus
public:
    GameCamera();
    Vector2D &GetPosition();
    
};
#endif /* defined(__CS587_ShuaiSong__GameCamera__) */
