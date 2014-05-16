//
//  Jump.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/2/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Jump.h"

void Jump::Enter(GameActor* target)
{
    
    target->SetDrawable(_playerJumpSprite);
    target->GetPhysics()->SetSpeed(target->data.jumpSpeed, Vector2D::DOWN);
    
}
void Jump::Execute(GameActor * target,IStateController * stateController)
{
    if (target->GetPhysics()->GetVelocity().y >= 0)
    {
       //DEBUGLOG("%s","jump Exit");
        stateController->ChangeToState("falling");
    }
}
void Jump::Exit(GameActor * target)
{
    DEBUGLOG("%s","jump Exit");
}
Jump::Jump()
{
  _playerJumpSprite =  ResourceManager::GetInstance()->GetSprite("jump");
}