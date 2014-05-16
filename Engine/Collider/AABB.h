 //
//  AABB.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/20/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__AABB__
#define __CS587_ShuaiSong__AABB__

#include <iostream>
#include <SDL2/SDL.h>
#include "SDLRender.h"
#include "Vector2D.h"
#include "ICollider.h"
class AABB:public ICollider
{
public:
    static bool debugToggle;                           // use for debug the aabb bounding box
    SDL_Renderer *render;
    int x;
    int y;
    int w;
    int h;
    
    
    AABB():x(0),y(0),w(0),h(0),ICollider(RECTANCLE)
    {
        render=SDL_CreateRenderer(SDLRender::window, 1, SDL_RENDERER_ACCELERATED);
        
    };
    AABB(int x,int y,int w,int h):x(x),y(y),w(w),h(h),ICollider(RECTANCLE)
    {
        render=SDL_CreateRenderer(SDLRender::window, -1, SDL_RENDERER_ACCELERATED);
        
    };
    inline void SetRect(SDL_Rect targetRect)
    {
        x=targetRect.x;
        y=targetRect.y;
        w=targetRect.h;
        h=targetRect.w;
    }
    void DebugDraw(const Vector2D & pos);
    inline SDL_Rect GetSDLRect()const
    {
        SDL_Rect tmp={x,y,w,h};
        return tmp;
    }
    
    //bool DoCollide(RectCollider targetCollider);
    bool IsIntersect(const AABB &targetCollider)const;
    bool IsIntersect(SDL_Rect rect);
    bool IsContainPoint(Vector2D &points);
    int GetTop()const;
    int GetBottom()const;
    int GetRight()const;
    int GetLeft()const;
    bool IsContain(const AABB &aabb)const;
    bool IsContain (ICollider * collider);
    const Vector2D & GetCenter();
    virtual void CreatWithDrawable(Vector2D & pos ,IDrawable *drawable);
    
};
#endif /* defined(__CS587_ShuaiSong__AABB__) */
