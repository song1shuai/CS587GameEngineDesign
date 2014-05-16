//
//  DebugManager.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/9/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__DebugManager__
#define __CS587_ShuaiSong__DebugManager__

#include <iostream>
#include "HashMap.h"
#include "DebugChannel.h"
/*
 make the use of the debugManager become more easier
 
 */


#define DEBUGCLOG(a,b,...) DebugManager::GetInstance()->DebugChannnel(a,b,__VA_ARGS__)
#define DEBUGLOG(a,...) DebugManager::GetInstance()->Debug(a,__VA_ARGS__)


class DebugManager
{
/*
 Use for control the debug channel object
*/
    
private:
    
    HashMap<DebugChannel*> _channelMap;         // use for store the debug channel object
    static DebugManager *_instance;
    DebugManager(){};                           // Keeo the class as a sington .
    
public:
    static DebugManager * GetInstance()
    {
        if (_instance==NULL)
        {
            _instance= new DebugManager();
        }
        return _instance;
    }
    
    DebugChannel* GetChannel(std::string channelName);
    
    void CreatChannel(std::string channelName);
    void RemoveChannel(std::string channelName);
    
    void TurnOnChannel(std::string channelName);
    void TurnOffChannel(std::string channelName);
    void DebugChannnel(std::string channelName ,const char* format, ...);
    void Debug(const char* format, ...);

    
};
#endif /* defined(__CS587_ShuaiSong__DebugManager__) */
