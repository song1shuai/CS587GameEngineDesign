//
//  Camera.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/26/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Camera.h"
void Camera::SetPosition(const Vector2D & pos)
{
    _position = pos;
}
Vector2D &Camera::GetPosition()
{
    return _position;
}
