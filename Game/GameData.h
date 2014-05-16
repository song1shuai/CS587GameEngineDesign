//
//  GameData.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__GameData__
#define __CS587_ShuaiSong__GameData__
#include <iostream>
#include "PlayerController.h"
#include "GameActor.h"
#include "BackgroudLayer.h"
#include "ObstacleSpawner.h"

class GameData
{
    

public:
    
     GameData():runnerController(NULL),runner(NULL){};
     PlayerController* runnerController;
     GameActor * runner;
     BackgroudLayer backGround;
     float ground;
};

#endif /* defined(__CS587_ShuaiSong__GameData__) */
