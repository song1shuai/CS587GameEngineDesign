//
//  ISceneNode.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/27/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__ISceneNode__
#define __CS587_ShuaiSong__ISceneNode__

#include <iostream>
#include <string>
#include "JValue.h"
#include "Vector2D.h"
#include "AABB.h"
#include "IQuadNode.h"
#include "UtilityFuc.h"
#include "ICollider.h"

class Vector2D;
class Actor;
class QuadTree;
class QuadNode;

class ISceneNode
{

    friend class QuadNode;
protected:
    
    std::string  _name;
    ISceneNode * _parent;
   
    QuadNode * _quadNode;
    QuadTree * _quadTree;
    int _ID;
    Actor*     _owner;
    
public:
   
    ISceneNode()
    {
        _parent= NULL;
        _owner = NULL;
         _ID = GetUniqueID();
    }
    
    ISceneNode(Actor* owner)
    :_owner(owner),
    _parent(NULL)
    {
         _ID = GetUniqueID();
    };

    ISceneNode(Actor* owner,
               ISceneNode * parent)
    :_owner(owner),
    _parent(parent)
    {
        _ID = GetUniqueID();
    
    };
    
    virtual ~ISceneNode(){};
    virtual const Vector2D &Getposition()=0;

    virtual void Render()=0;
    int GetID()
    {
        return _ID;
    }

    void SetParent(ISceneNode * parent)
    {
        _parent = parent;
    }
    
    ISceneNode* GetParent()
    {
        return _parent;
    }
    inline void SetName(std::string name)
    {
        _name=name;
    }
    inline std::string GetName()
    {
        return _name;
    }

    
    virtual Actor * GetOwnerActor()
    {
        return _owner;
    }
    virtual  ICollider * GetCollider()=0;
    



};





#endif
