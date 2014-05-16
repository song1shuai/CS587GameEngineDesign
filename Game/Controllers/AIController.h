//
//  AIController.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/25/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__AIController__
#define __CS587_ShuaiSong__AIController__

#include <iostream>
#include "ITickable.h"
#include "Actor.h"
#include "SceneManager.h"
#include "StateMachine.h"
class AIController
{
private:
    
    
    
public:  
    
    AIController(Actor* owner);
   
    virtual ~AIController(){};
    
    void Tick(float dt);
    void Update();
        
};
#endif /* defined(__CS587_ShuaiSong__AIController__) */
