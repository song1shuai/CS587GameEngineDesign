//
//  ICamera.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__ICamera__
#define __CS587_ShuaiSong__ICamera__

#include <iostream>
#include "Vector2D.h"
class ICamera
{
public:
    virtual Vector2D &GetPosition()=0;
};
#endif /* defined(__CS587_ShuaiSong__ICamera__) */
