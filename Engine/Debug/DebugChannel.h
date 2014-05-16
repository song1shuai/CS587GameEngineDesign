//
//  DebugChannel.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/8/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__DebugChannel__
#define __CS587_ShuaiSong__DebugChannel__

#include <iostream>
class DebugChannel
{
/*
    The class the debugChannel object.
 */
    
    
private:
    std::string _name;
    bool _isOpen;
public:
    DebugChannel():_isOpen(true){};
    inline void TurnOn()
    {
        _isOpen = true;
    }
    inline void TurnOff()
    {
        _isOpen = false;
    }
    inline bool IsOpen()
    {
        return _isOpen;
    }
    inline std::string GetName()
    {
        return _name;
    }
    
    
};

#endif /* defined(__CS587_ShuaiSong__DebugChannel__) */
