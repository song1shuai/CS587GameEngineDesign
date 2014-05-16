//
//  Game.h
//  sdl
//
//  Created by shuai song on 1/15/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __sdl__Game__
#define __sdl__Game__

#include <iostream>
#include <SDL2/SDL.h>
#include "SceneManager.h"
#include "TextureManager.h"
#include "Actor.h"
#include "PlayerController.h"
#include "GameActor.h"
#include "InputManager.h"
#include "QuadNode.h"
#include "Sprite.h"
#include "BackgroudLayer.h"
#include "ActorSceneNode.h"
#include "ResourceManager.h"
#include "Timer.h"


class SceneManager;
class Game
{
    
private:
    bool    _isStop;
    
    int     _lastFrameTime;
    int     _frameTime;
    
public:
    
    /**
     *@brief Use for game handle the play input
     *
     */
    
     Game();
    ~Game();
    
    /**
     *@brief
     *
     */
    //SceneManager * GetGameSence();
    
    void Run();
    bool InitEngine();
    void Render();
    void Updata();
    void SetFPS(int newFPS);

    
};

#endif /* defined(__sdl__Game__) */
