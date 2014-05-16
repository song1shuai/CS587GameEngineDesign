//
//  Timer.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/26/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Timer.h"
Timer::Timer()
{

    _startTime=0;
    _interval=0;
}
void Timer::Start()
{
    _startTime=SDL_GetTicks();
}

bool Timer::IsExpired()
{
    _currentTime  = SDL_GetTicks();
    
    
return  _currentTime - _startTime > _interval;
    
    

}
void Timer::SetInterval(int interval)
{
    _interval=interval*1000;
}