//
//  PlayerController.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/25/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__PlayerController__
#define __CS587_ShuaiSong__PlayerController__

#include "ITickable.h"
#include "ActorEvent.h"
#include "GameActor.h"
#include "Inputlistener.h"
#include "BitArray.h"
#include "InputManager.h"
#include "IEventBusListener.h"
#include "StateMachine.h"
#include "Engine.h"
#include "JValue.h"
#include "Jump.h"
#include "Move.h"
#include "Falling.h"

class PlayerController:public IKeyboardListener,public  IEventBusListener,public ITickable
{
private:
    
    GameActor*    _owner;             //The owner of this controller
    int           _lastStamp;         //The last time stamp
    BitArray      _keyState;
    StateMachine<GameActor>  _stateMachine;
    
public:
    
    ~PlayerController();
    PlayerController(GameActor *owner);
    

    
    
    void Tick(float dt);                // Use for update gamelogic
    
    
    
    void OnKeyDown(int key);            
    void OnKeyUp(int key);
    
    void OnEvent(IEvent *e);            //handle the event

    
};


#endif /* defined(__CS587_ShuaiSong__PlayerController__) */
