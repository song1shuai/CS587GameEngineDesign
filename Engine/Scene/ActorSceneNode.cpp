//
//  ActorSceneNode.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/19/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "ActorSceneNode.h"



ICollider* ActorSceneNode::GetCollider()
{
    return this->_owner->GetCollider();
}
Vector2D const & ActorSceneNode::Getposition()
{

    return  _owner->GetPosition()+ this->GetParent()->Getposition();
}

void ActorSceneNode::Render()
{
    
    Vector2D worldPos =this->Getposition();
    this->_owner->GetDrawable()->Draw(worldPos);
    //UpdateAABB();
    _owner->GetCollider()->DebugDraw(worldPos);
    
}

void ActorSceneNode::UpdateCollider()
{
    
    
    if (_quadNode!=NULL)
    {
        //_quadNode->Update(this, _quadNode);
    }
}
