//
//  EventBus.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/6/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__EventBus__
#define __CS587_ShuaiSong__EventBus__

#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Heap.h"
#include "IEvent.h"
#include "HashMap.h"
#include "IListener.h"
#include "UtilityFuc.h"
#include "EventBus.h"

typedef DynamicArray<IListener *> LISTENERLIST;
typedef HashMap<LISTENERLIST > LISTENERMAP;

class EventBus
{
    friend class IEventBusListener;
    

private:
    
    static EventBus*    _instance;         // the instance used for access this class
    EventBus();                            // Keep this class as a sington
    
    Heap<IEvent*>*      _eventQueue;       // The eventqueue for pooling the event in the bus
    LISTENERMAP         _listenerMap;      // The listener Map stone the list of different of listener
    
public:
    
    static EventBus * GetInstance()
    {
        if (_instance==NULL)
        {
            _instance= new EventBus();
        }
        return _instance;
    }
    
    ~EventBus()
    {
        delete _eventQueue;
    }
    
    
    void Dispatch(IEvent * e);                  //Dispacth the event without delay time
    void Dispatch(IEvent * e ,int delayTime);   //Dispatch of the event with delay time
    
    void AddListener(IListener *listener,std::string type);     // add the event listner to the map
    void RemoveListener(IListener *listener,std::string type);  // remove the listener from the list
    void Update();                                              //  pool the experied event from the queue 
   
    
};



#endif

