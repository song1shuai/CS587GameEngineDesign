//
//  IState.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/6/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IState_h
#define CS587_ShuaiSong_IState_h
#include "ITickable.h"
#include "IStateController.h"
template <typename T>
class IState
{
public:
    bool IsChange;
    virtual ~IState(){};
    virtual void Enter(T * target)=0;
    virtual void Execute(T * target,IStateController * stateController)=0;
    virtual void Exit(T * target)=0;
};


#endif
