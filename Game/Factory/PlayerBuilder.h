//
//  PlayerBuilder.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/11/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__PlayerBuilder__
#define __CS587_ShuaiSong__PlayerBuilder__

#include <iostream>
#include "IBuilder.h"
#include "GameActor.h"
#include "PlayerPhysics.h"
#include "Sprite.h"
#include "PlayerPhysics.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include <assert.h>

class PlayerBuilder
{
private:
    GameActor * _playerActor;
public:
    PlayerBuilder():_playerActor(NULL){};
    ~PlayerBuilder();
    virtual GameActor* GetNewActor();
    virtual void BuildActor(ActorData * data);
    virtual void AddToScene();
    
};
#endif /* defined(__CS587_ShuaiSong__PlayerBuilder__) */
