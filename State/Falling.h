//
//  Falling.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__Falling__
#define __CS587_ShuaiSong__Falling__
#include "IState.h"
#include "GameActor.h"
#include "Engine.h"
#include "Sprite.h"
#include <iostream>
class Falling:public IState<GameActor>
{
private:
    Sprite * _playerFallSprite;
public:
    Falling();
    ~Falling(){};
    void Enter(GameActor * target);
    void Execute(GameActor * target,IStateController * stateController);
    void Exit(GameActor* target);
    
};
#endif /* defined(__CS587_ShuaiSong__Falling__) */
