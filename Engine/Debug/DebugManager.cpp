//
//  DebugManager.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/9/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "DebugManager.h"
DebugManager *DebugManager::_instance=NULL;
DebugChannel* DebugManager::GetChannel(std::string channelName)
{
    return *_channelMap.Find(channelName);
}
void DebugManager::CreatChannel(std::string channelName)
{
    _channelMap.Insert(channelName, new DebugChannel());
}
void DebugManager::TurnOnChannel(std::string channelName)
{
    DebugChannel * channel = *_channelMap.Find(channelName);
    if (channel!= NULL)
    {
        channel->TurnOn();
        return;
    }
    
}
void DebugManager::TurnOffChannel(std::string channelName)
{
    DebugChannel * channel = *_channelMap.Find(channelName);
    if (channel!= NULL)
    {
        channel->TurnOff();
        return;
    }
    
}
void DebugManager::DebugChannnel(std::string channelName ,const char* format, ...)
{
    
    
    DebugChannel * channel = *_channelMap.Find(channelName);
    if (channel!= NULL && channel->IsOpen())
    {
      
        va_list args;
        va_start( args, format );
        std::cout << channelName << ":";
        vprintf( format, args );
        std::cout<<std::endl;
        va_end( args );
        
        return;
    }
    
}
 void DebugManager::Debug(const char* format, ...)
{
    va_list args;
    va_start( args, format );
    std::cout << "Engine"<< ":";
    vprintf( format, args );
    std::cout<<std::endl;
    va_end( args );
    return;
    
}
void DebugManager::RemoveChannel(std::string channelName)
{
    DebugChannel * channel = *_channelMap.Find(channelName);
    if (channel!= NULL)
    {
        _channelMap.Remove(channelName);
        delete channel;
        channel = NULL;
    }
    
}