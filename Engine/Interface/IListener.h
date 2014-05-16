//
//  IListener.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/8/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IListener_h
#define CS587_ShuaiSong_IListener_h
class IEvent;

class IListener
{
public:

    virtual void OnEvent(IEvent *e)=0;

    
};



#endif
