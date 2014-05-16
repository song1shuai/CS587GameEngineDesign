//
//  QuadTree.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/20/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__QuadTree__
#define __CS587_ShuaiSong__QuadTree__

#include <iostream>
#include "DynamicArray.h"
#include "Actor.h"
#include "Vector2D.h"
#include "QuadNode.h"
#include "AABB.h"


class QuadTree
{
    friend QuadNode;
    friend AABB;
    
private:
    
    QuadNode * _root;                               //root of the quad tree;
    
public:
    
    ~QuadTree();
    QuadTree(const AABB & region);
    QuadTree(){};
    void CreatQuadTree(int x,int y,int w,int h);    // Create the quad from the qiven region

    
    void DebugDraw();                               // use for debug the quad tree
    void Insert(ISceneNode * sceneNode);
    void Query(const AABB & region ,DynamicArray<ISceneNode *> & result); // return the object the intersect with that region .
    void Clear(const AABB & region);        // remove  all the node from the tree;
    QuadTree(int x,int y,int w,int h);
    int GetNumOfObject();                           // return the
    
};
#endif /* defined(__CS587_ShuaiSong__QuadTree__) */
