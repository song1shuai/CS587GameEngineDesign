//
//  QuadTree.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/20/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "QuadTree.h"

void QuadTree::Insert(ISceneNode * sceneNode)
{
    if (_root->_bb.IsContain(sceneNode->GetCollider()))
    {
        _root->Insert(sceneNode);
    }
    
}
void QuadTree::Query(const AABB & region ,DynamicArray<ISceneNode *> & result)
{
    	_root->Query(region, result);
    
}
void QuadTree::Clear(const AABB & region)
{
    

}
 QuadTree::QuadTree(const AABB & region)
{
    
    _root= QuadNode::CreatNode(0,region.x,region.y ,region.w, region.h,NULL,this);
    
}
QuadTree::~QuadTree()
{
	delete _root;
}
QuadTree::QuadTree(int x,int y,int w,int h)
{
    
    _root= QuadNode::CreatNode(0,x,y ,w, h,NULL,this);
    
}
void QuadTree::CreatQuadTree(int x,int y,int w,int h)
{
     _root= QuadNode::CreatNode(0,x,y ,w, h,NULL,this);
}
void QuadTree::DebugDraw()
{
    _root->Draw();
}
int QuadTree::GetNumOfObject()
{
  return   _root-> _numberOfObject;
}