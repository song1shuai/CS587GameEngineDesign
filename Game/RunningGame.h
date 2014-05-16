//
//  RunningGame.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/11/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__RunningGame__
#define __CS587_ShuaiSong__RunningGame__

#include <iostream>
#include "Game.h"
#include "DebugManager.h"
#include "ActorFactory.h"
#include "PlayerBuilder.h"
#include "GameData.h"
#include "ObstacleSpawner.h"
class RunningGame:public Game
{
private:
 
    GameActor * _runner;
    PlayerController * _playerController;
    GameData _gameData;
    ObstacleSpawner * _obstacleSpawner;
    
public:
    bool Init();
    void ConfigGame();

};
#endif /* defined(__CS587_ShuaiSong__RunningGame__) */
