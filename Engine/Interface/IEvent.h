//
//  IEvent.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/8/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IEvent_h
#define CS587_ShuaiSong_IEvent_h
#include "DynamicArray.h"
//#include "IListener.h"
#include <SDL2/SDL.h>
#include <string>
class IListener;
class IEvent
{
    
public:
    
    virtual ~IEvent(){};
    IEvent(std::string eventType)
    {
        type=eventType;
    }
    int stamp;
    std::string type;
    
};


#endif
