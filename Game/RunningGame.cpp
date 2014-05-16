//
//  RunningGame.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/11/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "RunningGame.h"
bool RunningGame::Init()
{
    if (!Game::InitEngine())
    {
        DEBUGLOG("%s","Can not init engine");
        return false;
    }
    ConfigGame();

    /*
     TODO:
     Those part should be date driven...........
     
     
     */
    
    
    SceneManager::GetInstance()->AddLayer(&_gameData.backGround,0);
    LayerNode * obstacle = SceneManager::GetInstance()->AddLayer("obstacle",1);
    
    obstacle->Move(Vector2D(-2,0.0));
    LayerNode * playerLayer = SceneManager::GetInstance()->AddLayer("player",2);
   
    ISceneNode* player = SceneManager::GetInstance()->AddActorToLayer("player", _gameData.runner);
    
    
    SceneManager::GetInstance()->_quadtree.Insert(player);
    
    ObstacleSpawner * _obstacleSpawner = new ObstacleSpawner(_gameData.runner);


    

    
     return true;
}

void RunningGame::ConfigGame()
{
    _gameData.runner = ActorFactory::GetInstance()->GetActor("playerActor");
    

    _gameData.runnerController = new PlayerController( _gameData.runner );
    _gameData.backGround.Init();
    SceneManager::GetInstance()->AddTickable(_gameData.runnerController);
    
}