//
//  Obstacles.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/22/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Obstacles.h"
//Obstacles::Obstacles(const Obstacles & target)
//{
//
//}
Obstacles::Obstacles(int x,int y)
{

    
}
Obstacles::Obstacles()
{
     weight=0;
    _drawable = new Drawable();
}
Obstacles::~Obstacles()
{
    if (_drawable!=NULL)
    {
        delete _drawable;
        _drawable = NULL;
    }
}
Obstacles * Obstacles::Clone()
{
    return new Obstacles(*this);
}
