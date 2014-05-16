//
//  Move.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Move.h"
void Move::Enter(GameActor * target)
{
    target->SetDrawable(_playerMoveSprite);
}
void Move::Execute(GameActor * target,IStateController * stateController)
{
 
    
}
void Move::Exit(GameActor* target)
{
    
}
 Move::Move()
{
    _playerMoveSprite =  ResourceManager::GetInstance()->GetSprite("move");
}