//
//  GameActor.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/1/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "GameActor.h"

GameActor::~GameActor()
{
    
    if (_drawable != NULL)
    {
        delete _drawable;
        _drawable = NULL;
    }
    if (_physics != NULL)
    {
        delete _physics;
        _physics = NULL;
    }
    if (_collider != NULL)
    {
        delete _collider;
        _collider = NULL;
    }
    
    
}
 GameActor::GameActor()
{

    JumpSpeed = Vector2D::ZERO;
    RunSpeed  = Vector2D::ZERO;
    
};
ICollider *  GameActor::GetCollider()
{
    _collider->CreatWithDrawable(_position, _drawable);
    return _collider;
}
const Vector2D& GameActor::GetCenter()
{
    _center.x = this->_drawable->GetRect().w/2;
    _center.y = this->_drawable->GetRect().h/2;
    
    return _center;

}
