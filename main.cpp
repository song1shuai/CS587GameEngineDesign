////
////  main.cpp
////  sdl
////
////  Created by shuai song on 1/15/14.
////  Copyright (c) 2014 shuai song. All rights reserved.
////
//
#include "Game/Game.h"
#include "RunningGame.h"
#include <iostream>
#include "ObstacleSpawner.h"
using namespace std;


int main( int argc, char* args[] )
{
    
    RunningGame game;
    game.Init();
    game.Run();
}

