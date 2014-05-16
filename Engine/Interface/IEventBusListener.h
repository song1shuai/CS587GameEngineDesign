//
//  IEventBusListener.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/6/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IEventBusListener_h
#define CS587_ShuaiSong_IEventBusListener_h
#include "IListener.h"
#include "EventBus.h"
class IEventBusListener:public IListener
{
public:
    virtual ~IEventBusListener(){};
    virtual void OnEvent(IEvent *e)=0;
    static void AddListener(std::string type, IListener* listener )
    {
     LISTENERLIST* listenerList=EventBus::GetInstance()->_listenerMap.Find(type);
        

        if( listenerList==NULL)
        {
            listenerList = new LISTENERLIST();
            listenerList->InsertAtLast(listener);
            EventBus::GetInstance()->_listenerMap.Insert(type, *listenerList);
        }
        else
        {
            listenerList->InsertAtLast(listener);
        }
    }
    static void RemoveListener(std::string type, IListener* listener)
    {
     
        LISTENERLIST* listenerList=EventBus::GetInstance()->_listenerMap.Find(type);
    
        if( listenerList!=NULL)
        {
           listenerList->Remove(listener);
            
        }
        
        if (listenerList->GetLength()==0)
        {
            EventBus::GetInstance()->_listenerMap.Remove(type);
        }
    }
};

#endif
