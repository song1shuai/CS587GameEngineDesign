//
//  LayerNode.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/29/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "LayerNode.h"
int LayerNode::_systermZOrder=0;
Vector2D const &LayerNode::Getposition()
{
    
    return _position;
}
ICollider * LayerNode::GetCollider()
{
    return this->GetOwnerActor()->GetCollider();
    
}
void LayerNode::DeserializeAttributes(JValue * attributes)
{
    
}
void LayerNode::Render()
{
    
}
void LayerNode::AddChild(ISceneNode * child)
{
    _childrenList.InsertAtLast(child);
    child->SetParent(this);
    
}
void LayerNode::RemoveAll()
{
    for(int i=0;i<_childrenList.GetLength();i++)
    {
        _childrenList[i]->SetParent(NULL);
        _childrenList.Remove(_childrenList[i]);
    }
}
void LayerNode::RemoveChild(ISceneNode * child)
{
    
    child->SetParent(NULL);
    _childrenList.Remove(child);
}
void LayerNode::Draw()
{
    
    
    // Update the position of this layer baed on velocity
    _position+=_velocity;
    for (int i = 0; i < _childrenList.GetLength(); ++i)
    {
        _childrenList[i]->Render();

    }


}
 void LayerNode::Move(const Vector2D & dir)
{
    _velocity = dir;
}