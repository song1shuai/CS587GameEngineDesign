//
//  ObstacleSpawner.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/23/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__ObstacleSpawner__
#define __CS587_ShuaiSong__ObstacleSpawner__

#include <iostream>
#include "MemoryPool.h"
#include "Obstacles.h"
#include "ITickable.h"
#include "Vector2D.h"
#include "IDrawable.h"
#include "Engine.h"
#include "Drawable.h"
#include <SDL2/SDL.h>
#include "HashMap.h"
#include "Timer.h"
#include "GameActor.h"

class ObstacleSpawner:public ITickable
{
private:
    
    HashMap<Obstacles*>      _obstacles;
    DynamicArray<Obstacles*> _obstacleArray;
    
    Timer                    _timer;
    int                      _numOfObtacles;
    Vector2D                 _nextpos;
    GameActor*               _player;
    
    
    
public:
    
    void Tick(float dt);
    ObstacleSpawner( GameActor* player);
    void RegisterObstacle(Obstacles * obstacle);
    void GenerateObstacle(const Vector2D & pos,int i);
    Obstacles *GetObstacle(std::string name);
    void Deserialize();
    

    
};

#endif /* defined(__CS587_ShuaiSong__ObstacleSpawner__) */
