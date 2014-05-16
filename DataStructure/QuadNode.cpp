//
//  QuadNode.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/19/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "QuadNode.h"
const  int QuadNode::_capacity =1;
const  int QuadNode::_maxLevel = 5;
MemoryPool<QuadNode> QuadNode::pool;
QuadNode::QuadNode(int level,AABB bound,QuadNode * parent,QuadTree * tree)
{
    _level=level;
    _bb = bound;
    _isLeaf = true;
    _parent = parent;
    _tree = tree;
    _numberOfObject = 0;
    
}
AABB &QuadNode::GetAABB()
{
    return _bb;
}
void QuadNode::Draw()
{
    
   // _bb.DebugDraw(Vector2D::ZERO);
    
    for (int i = 0; i < 4; i ++)
    {
        if (_children[0]==NULL)
        {
           
            return;
            
        }
         _children[i]->Draw();
       
    }
}
bool QuadNode::IsLeaf()
{
    return  _isLeaf;
}

void QuadNode::SetLeaf(bool isLeaf)
{
    _isLeaf=isLeaf;
}

void QuadNode::Insert(ISceneNode * sceneNode)
{
 
    
    _numberOfObject++;
    
    if (_children[0]!=NULL)
    {
        int numOfChild = PositionInChild(sceneNode->GetCollider());
        if (numOfChild != -1)
        {
            _children[numOfChild]->Insert(sceneNode);
            
            return;
        }
    }
    _objlist.InsertAtLast(sceneNode);
    sceneNode->_quadNode = this;
    sceneNode->_quadTree=_tree;

    if (_objlist.GetLength()>_capacity &&_level < _maxLevel)
    {
        if (_children[0]==NULL)
        {
            Subdivide();
        }
        
        int i = 0;
        while (i < _objlist.GetLength())
        {
           int numOfChild = PositionInChild(sceneNode->GetCollider());
            if (numOfChild!=-1)
            {
                _children[numOfChild]->Insert(sceneNode);
                _objlist.RemoveAtIndex(i);
            }
            else
            {
                i++;
            }
        }
    }

}

bool QuadNode::Subdivide()
{

    if (_children[0]==NULL)
    {
       
        _children[TL]=QuadNode::CreatNode(this->_level+1,GetAABB().GetLeft(),GetAABB().GetTop(),GetAABB().w/2,GetAABB().h/2,this,_tree);
        _children[TR]=QuadNode::CreatNode(this->_level+1,GetAABB().GetCenter().x,GetAABB().GetTop(),GetAABB().w/2,GetAABB().h/2,this,_tree);
        _children[BR]=QuadNode::CreatNode(this->_level+1,GetAABB().GetCenter().x,GetAABB().GetCenter().y,GetAABB().w/2,GetAABB().h/2,this,_tree);
        _children[BL]=QuadNode::CreatNode(this->_level+1,GetAABB().GetLeft(),GetAABB().GetCenter().y,GetAABB().w/2,GetAABB().h/2,this,_tree);
        _isLeaf = false;

    }
    

    return true;
    

    
}
QuadNode::QuadNode(int level,int x,int y ,int w,int h,QuadNode * parents,QuadTree * tree)
{
    this->_level = level;
    _isLeaf = true;
    _bb.x=x;
    _bb.y=y;
    _bb.w=w;
    _bb.h=h;
    _parent = parents;
    _tree = tree;
    
    _numberOfObject = 0;
    DEBUGLOG("%d,%d,%d,%d,%d",_level,_bb.x,_bb.y,_bb.w,_bb.h);
    for (int i = 0; i <4 ; ++i)
    {
        _children[i]=NULL;
    }
    DEBUGLOG("%d,%d",_bb.GetCenter().x,_bb.GetCenter().y);
    
    _isLeaf=true;

    
}
QuadNode *QuadNode::CreatNode(int level,int x,int y ,int w,int h,QuadNode * parents,QuadTree * tree)
{
    
    
    // allocate  the node from the pool
    QuadNode * node = pool.Allocate();
    
 
    // created the instance and return
    return new(node)QuadNode(level, x, y , w, h,parents,tree);
}
void QuadNode::DeleteNode(QuadNode * node)
{

    pool.Free(node);
    node = NULL;
    
}

void QuadNode::Query(const AABB &queryRegion, OBJLIST &queryResult)
{

    
    
    int numOfChildren = PositionInChild(queryRegion);
    
    if (numOfChildren != -1 && _children[0]!=NULL)
    {
        _children[numOfChildren]->Query(queryRegion, queryResult);
   
    }
    
    

    
    
      return;
    
    
    
    
}
void QuadNode::Update(ISceneNode * sceneNode,QuadNode * quadNode)
{
    /*
     
     remove the scene node from current node .
     if the node do not  move out of current node the insert it in the 
     current node  ,otherwise insert it from its parents node .
     */
    
    
    
    _objlist.Remove(sceneNode);
 

    if (_bb.IsContain(sceneNode->GetCollider()))
    {
        _numberOfObject--;
        this->Insert(sceneNode);
        
    }
    
    else
    {
        
        if (_numberOfObject<=0)
        {
            while (quadNode->_parent!=NULL)
            {
                if (_numberOfObject >=0)
                {
                    break;
                }
                
       /*
        if the number of the object less than the capacity 
        merge this level from parents
        */
                
               quadNode = quadNode->_parent;
            }
            
            quadNode->Merge();
        }
        
        while (quadNode!=NULL)
        {
            _numberOfObject--;
            if (quadNode->_bb.IsContain(sceneNode->GetCollider()))
            {
                quadNode->Insert(sceneNode);
                return;
            }
            quadNode = quadNode->_parent;
            
        }
    }
    
    return;
    
    
}
 void QuadNode::Merge()
{
    /*
     merge the  children level in to this level 
     and delete all the children node .
     */
    
    
    if (!_isLeaf)
    {

        
        for (int i = 0; i < 4; i++)
        {
            _children[i]->GetObjectFromChildren(_objlist, this);
            
        }
    }
    
     DestroyChildren();
     _isLeaf = true;
    
}
void QuadNode::GetObjectFromChildren(OBJLIST & childrenObjList,QuadNode * newNode)
{
    /*
     use for get the scene node stored in the children node
     
     */
    
    
    for (int i = 0; i < _objlist.GetLength(); i++)
    {
        _objlist[i]->_quadNode = newNode;
        childrenObjList.InsertAtLast(_objlist[i]);
    }
    if (!_isLeaf)
    {
        for (int i =0 ; i < 4; i++)
        {
            _children[i]->GetObjectFromChildren(childrenObjList, newNode);
        }
    }
    
}
void QuadNode::DestroyChildren()
{
    for (int i = 0; i < 4; i++)
    {
        if (_children[i]!=NULL)
        {
            QuadNode::DeleteNode(_children[i]);
            _children[i]=NULL;
        }
    }
    
}
void QuadNode::RemoveObject(ISceneNode *sceneNode)
{
    for (int i = 0 ; i < _objlist.GetLength() ; i++)
    {
        if (sceneNode == _objlist[i])
        {
            _objlist.RemoveAtIndex(i);
            _numberOfObject--;
            if (_numberOfObject<=_capacity)
            {
                Merge();
            }
            break;
        }
        
    }
    
    return;
    
}


int QuadNode::PositionInChild(const AABB & aabb)
{
    /*
     The function return potential region of the aabb should be in  
     
     */
    
    
    if (aabb.x<_bb.GetCenter().x&&aabb.y<_bb.GetCenter().y)
    {
        
        return TL;
        
    }
    
    if (aabb.x>=_bb.GetCenter().x&&aabb.y<=_bb.GetCenter().y)
    {
        
        return TR;
    }
    if (aabb.x<_bb.GetCenter().x&&aabb.y>_bb.GetCenter().y)
    {
        
        return BL;
    }
    if (aabb.x>_bb.GetCenter().x&&aabb.y>_bb.GetCenter().y)
    {
        return BR;
    }

    
    return -1;
}
int  QuadNode::PositionInChild(ICollider* collider)
{

 return    PositionInChild(*static_cast<AABB*>(collider));
}
