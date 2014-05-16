//
//  Jump.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/2/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__Jump__
#define __CS587_ShuaiSong__Jump__

#include <iostream>
#include "IState.h"
#include "GameActor.h"
#include "Engine.h"
#include "Sprite.h"
#include "Inputlistener.h"
class Jump:public IState<GameActor>
{
private:
    Sprite * _playerJumpSprite;
public:
    Jump();
    ~Jump(){};
    void Enter(GameActor * target);
    void Execute(GameActor * target,IStateController * stateController);
    void Exit(GameActor* target);
    
};
#endif /* defined(__CS587_ShuaiSong__Jump__) */
