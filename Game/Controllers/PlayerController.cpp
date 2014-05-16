//
//  PlayerController.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/25/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "PlayerController.h"
PlayerController::PlayerController(GameActor *owner):_stateMachine(owner),_owner(owner)
{
    //_owner=owner;
    InputManager::GetInstance()->AddKeyboardListener(this);
    this->AddListener(ActorEvent::DEATH_EVENT, this);
    _stateMachine.AddState("jump", new Jump());
    _stateMachine.AddState("move", new Move());
    _stateMachine.AddState("falling", new Falling);
    _stateMachine.ChangeToState("move");
}

PlayerController::~PlayerController()
{
    InputManager::GetInstance()->RemoveKeyboardListener(this);
    
    this->RemoveListener(ActorEvent::DEATH_EVENT, this);
}
void PlayerController::Tick(float dt)
{

    if (_keyState[SDL_SCANCODE_SPACE])
    {
      
        _stateMachine.ChangeToState("jump");
        
    }
    

    _stateMachine.Update();
    _owner->GetPhysics()->Update(dt);
    
}


 void PlayerController::OnKeyDown(int key)
{
    
    _keyState.Set(key, true);
}
 void PlayerController::OnKeyUp(int key)
{
    _keyState.Set(key, false);
}
 void PlayerController::OnEvent(IEvent *e)
{
    
    
    DEBUGLOG("%s","im die");
}
