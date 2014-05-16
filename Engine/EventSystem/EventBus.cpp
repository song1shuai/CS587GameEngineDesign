//
//  EventBus.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/6/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "EventBus.h"
EventBus * EventBus::_instance=NULL;

void EventBus::Dispatch(IEvent * e)
{
    e->stamp =SDL_GetTicks();
    _eventQueue->Insert(e);
    
    
}
void EventBus::Dispatch(IEvent * e ,int delayTime)
{
    // add the time stamp to current event compute the experied time
    
    e->stamp =SDL_GetTicks()+delayTime*1000;
    
    _eventQueue->Insert(e);
    
}
EventBus::EventBus()
{
    _eventQueue = new Heap<IEvent*>(compare);
    
};
void EventBus::Update()
{
    
    /*
        pool all the expiered event from the event queue
        if the map has the listener listen this type of
        event notif the event to the listener.otherwise 
        delete the event.
     */
 
    int time = SDL_GetTicks();
    
    for (int i = 0; i < _eventQueue->GetLength(); ++i)
    {
        IEvent * e = _eventQueue->PopMax();
        if (time<=e->stamp)
        {
            _eventQueue->Insert(e);
            break;
        }

        
        LISTENERLIST *listenerList = _listenerMap.Find(e->type);
        if (listenerList==NULL)
        {
            delete e;
            continue;
        }
        
        else
        {
        //  Send event to all listeners;
            for (int i = 0; i < listenerList->GetLength(); ++i)
            {
                std::cout<<e->stamp<<std::endl;
                (*listenerList)[i]->OnEvent(e);
                
            }
            
            delete e;
        }
      
        
    }
    
}
void EventBus::AddListener(IListener *listener,std::string type)
{

    _listenerMap.Find(type)->InsertAtLast(listener);
    
}
void EventBus::RemoveListener(IListener *listener,std::string type)
{
    
    
    _listenerMap.Find(type)->Remove(listener);
}
