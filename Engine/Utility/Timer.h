//
//  Timer.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/26/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__Timer__
#define __CS587_ShuaiSong__Timer__

#include <iostream>
#include "Timer.h"
#include <SDL2/SDL.h>
#include "SceneManager.h"
#include "ITickable.h"
class Timer
{
private:
    
    int _startTime;
    int _interval;
    int _currentTime;
    
    
    
public:
    Timer();
    void Start();
    bool IsExpired();
    void SetInterval(int interval);
};
#endif /* defined(__CS587_ShuaiSong__Timer__) */
