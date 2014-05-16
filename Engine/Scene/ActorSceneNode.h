//
//  ActorSceneNode.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/19/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__ActorSceneNode__
#define __CS587_ShuaiSong__ActorSceneNode__

#include <iostream>
#include "Vector2D.h"
#include "DynamicArray.h"
#include "AABB.h"
#include "ISceneNode.h"
#include "Actor.h"
#include "QuadNode.h"
class ActorSceneNode:public ISceneNode
{
private:
    
    
public:
    
    ActorSceneNode(Actor * actor):ISceneNode(actor)
    {
    
    
    };
    ActorSceneNode(Actor * actor,
                   ISceneNode *partent
                   )
    :ISceneNode(actor,partent)
    {}

    virtual ~ActorSceneNode()
    {
        
    };
    ICollider* GetCollider();           // Get Collider from the actor
    virtual void Render();
    void UpdateCollider();                  //Update the Collider
    Vector2D const & Getposition();

};
#endif /* defined(__CS587_ShuaiSong__ActorSceneNode__) */
