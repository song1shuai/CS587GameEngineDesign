//
//  Falling.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Falling.h"
void Falling::Enter(GameActor * target)
{
    target->SetDrawable(_playerFallSprite);
}
void Falling::Execute(GameActor * target,IStateController * stateController)
{
    if (target->GetPhysics()->GetVelocity().y<0)
    {
        stateController->ChangeToState("jump");
    }
    if (target->GetPhysics()->isOnGround)
    {
        stateController->ChangeToState("move");
    }
    
}
void Falling::Exit(GameActor* target)
{
    
}
Falling::Falling()
{
    _playerFallSprite =  ResourceManager::GetInstance()->GetSprite("falling");
}