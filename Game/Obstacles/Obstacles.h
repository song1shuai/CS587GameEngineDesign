//
//  Obstacles.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/22/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__Obstacles__
#define __CS587_ShuaiSong__Obstacles__

#include <iostream>
#include "GameActor.h"
#include "Drawable.h"


class Obstacles:public GameActor
{

public:

    int weight;             //The weight used for generate the obstacles
    Obstacles(int x,int y);
    
    Obstacles * Clone();
    Obstacles();
    ~Obstacles();
    
};

#endif /* defined(__CS587_ShuaiSong__Obstacles__) */
