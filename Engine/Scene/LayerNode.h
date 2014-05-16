//
//  LayerNode.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/29/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__LayerNode__
#define __CS587_ShuaiSong__LayerNode__

#include <iostream>
#include "ISceneNode.h"
#include "AABB.h"
#include "Actor.h"
class LayerNode:public ISceneNode
{
protected:
    
    
    AABB                        _aabb;                  // The bouding box of current sceneNode
    DynamicArray<ISceneNode*>   _childrenList;          // The list of the sceneNode this layer should have
    static int                  _systermZOrder;         // The next aviable zOrder
    int                         _zOrder;                // The zOrder of the current layer;
    bool                        _isVisible;             // The visible toggle
    Vector2D                    _position;              // The position of this level
    Vector2D                    _velocity;              // The velocity of this level
    
public:
    LayerNode()
    {
        _position=Vector2D::ZERO;
        _zOrder=_systermZOrder;
        _systermZOrder++;
        _velocity=Vector2D::ZERO;
        _isVisible=true;
    }
    LayerNode(Actor * actor ,ISceneNode *parent=NULL):ISceneNode(actor,parent)
    {
    
        _velocity=Vector2D::ZERO;
        _zOrder=_systermZOrder;
        _systermZOrder++;
        _isVisible=true;
    };
    LayerNode(Actor * actor):ISceneNode(actor)
    {
        _velocity=Vector2D::ZERO;
        _zOrder=_systermZOrder;
        _systermZOrder++;
        _isVisible=true;
    }
   // LayerNode(){};
    ICollider * GetCollider();
    virtual void DeserializeAttributes(JValue * attributes);
    virtual void Render();
    void RemoveChild(ISceneNode * child);
    void RemoveAll();
    void AddChild(ISceneNode * child);
    inline void SetZOrder(int zOrder)
    {
        _zOrder=zOrder;
    }
    inline int GetZorder()
    {
        return _zOrder;
    }
    inline bool IsVisible()
    {
        return _isVisible;
    }
   virtual const Vector2D &Getposition();
   virtual void Draw();

  virtual  DynamicArray<ISceneNode *> &GetChildren()
  {
     return _childrenList;
  }
 void  Move(const Vector2D & dir);
    
};


#endif /* defined(__CS587_ShuaiSong__LayerNode__) */
