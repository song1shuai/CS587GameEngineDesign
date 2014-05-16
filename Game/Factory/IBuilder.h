//
//  IBuilder.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/10/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IBuilder_h
#define CS587_ShuaiSong_IBuilder_h
#include "Actor.h"
class IBuilder
{
public:
   // virtual void RegisterActor()=0;
    virtual Actor* GetNewActor()=0;
    virtual void BuildActor()=0;
    
};


#endif
