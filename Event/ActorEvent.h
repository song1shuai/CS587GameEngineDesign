//
//  ActorEvent.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_ActorEvent_h
#define CS587_ShuaiSong_ActorEvent_h
#include "IEvent.h"
#include "Actor.h"
#include<string>
#include <iostream>


class ActorEvent:public IEvent
{
    
private:
    Actor *_owner;
public:
    
    static const std::string DEATH_EVENT;
    ActorEvent( std::string type, Actor * owner ):_owner(owner),IEvent(type){};
    
};

#endif
