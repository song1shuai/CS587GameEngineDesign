//
//  QuadNode.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/19/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__QuadNode__
#define __CS587_ShuaiSong__QuadNode__

#include <iostream>
#include <SDL2/SDL.h>
#include "AABB.h"
#include "Actor.h"
#include "DynamicArray.h"
#include "MemoryPool.h"
#include "ISceneNode.h"
#include "DebugManager.h"
#include "IQuadNode.h"
enum child
{
    TL=0,
    TR,
    BL,
    BR
   
    
};


class QuadTree;

typedef DynamicArray<ISceneNode*> OBJLIST;
class QuadNode
{

    friend class QuadTree;
    friend class ISceneNode;
    friend class ActorSceneNode;

private:
    
    AABB        _bb;                //The  bounding box of the node
    QuadNode*	_children[4];       //The  child node
    OBJLIST     _objlist;           //The  list used stone the scene node
    QuadTree*   _tree;
    int         _level;             //The  level of the current node in the tree
    int         _numberOfObject;    //The  number scene node in this quad tree
    
    
    static bool _isDraw;            //The debug toggle
    bool        _isLeaf;
    
    QuadNode*   _root;             // The refernce to the root

    const static int _capacity;    // The capacity of the quadtree
    const static int _maxLevel;    // The max level of th quadtree
    
    static MemoryPool<QuadNode> pool; // The object pool
    
    
    bool Subdivide();
	void DestroyChildren();
	void Merge();
    
    
    
    
    int  PositionInChild( const AABB & aabb);

    int  PositionInChild(ICollider* ICollider);
    void GetObjectFromChildren(OBJLIST & _objList,QuadNode * newNode);
    
public:
    
    QuadNode* _parent;
    
    static QuadNode *CreatNode(int level,
                               int x,
                               int y,
                               int w,
                               int h,
                               QuadNode * parents,
                               QuadTree * tree
                               );
    
    static void DeleteNode(QuadNode * T);
    
    ~QuadNode()
    {
     
    
    
    }
    
    
    QuadNode(int level,
             AABB bound,
             QuadNode * parents,
             QuadTree * tree
             );
    
    QuadNode(int level,
             int x,
             int y,
             int w,
             int h,
             QuadNode * parents,
             QuadTree * tree
             );
    
    
 
    
    void Draw();
    AABB &GetAABB();
   
 
    void Insert(ISceneNode * sceneNode);
    void Update(ISceneNode * sceneNode,QuadNode * quadNode);        //up date current node
    void Query(const AABB &queryRegion, OBJLIST &queryResult);      
    void RemoveObject(ISceneNode *sceneNode);
  
    
    
    bool IsLeaf();
    void SetLeaf(bool isLeaf);
    int GetNumOfObject()
    {
        return _numberOfObject;
    }
 
 
};

#endif /* defined(__CS587_ShuaiSong__QuadNode__) */
