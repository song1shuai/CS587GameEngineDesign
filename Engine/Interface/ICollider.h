//
//  ICollider.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/18/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_ICollider_h
#define CS587_ShuaiSong_ICollider_h
#include "IDrawable.h"
class AABB;
enum ColliderType
{
    RECTANCLE,
    CIRCLE
};
/*
 TODO:
    Only have the AABB collider now .
    circle collider will be add in the future
 
 */

class ICollider
{
private:
    ColliderType type;
public:
    inline ColliderType GetType(){return type;};
    virtual ~ ICollider(){};
    ICollider (ColliderType type):type(type){};
    virtual const Vector2D & GetCenter()=0;
    virtual bool IsContain(const AABB &aabb)const=0;
    virtual bool IsIntersect(const AABB &targetCollider)const=0;
    virtual bool IsIntersect(SDL_Rect rect)=0;
    virtual bool IsContainPoint(Vector2D &points)=0;
    virtual void CreatWithDrawable(Vector2D & pos ,IDrawable *drawable)=0;
    virtual void DebugDraw(const Vector2D & pos)=0;
    
};


#endif
