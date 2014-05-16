//
//  ITickable.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_ITickable_h
#define CS587_ShuaiSong_ITickable_h

class ITickable
{
public:
    /**
     *@brief The tickable interface the child class must override tick function.
     *
     */

    virtual void Tick(float dt)=0;
};


#endif
