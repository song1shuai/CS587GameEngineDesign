//
//  Move.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__Move__
#define __CS587_ShuaiSong__Move__
#include "IState.h"
#include "GameActor.h"
#include "Engine.h"
#include "Sprite.h"
#include <iostream>
class Move:public IState<GameActor>
{
private:
    Sprite * _playerMoveSprite;
public:
    Move();
    ~Move(){};
    void Enter(GameActor * target);
    void Execute(GameActor * target,IStateController * stateController);
    void Exit(GameActor* target);
    
};
#endif /* defined(__CS587_ShuaiSong__Move__) */
