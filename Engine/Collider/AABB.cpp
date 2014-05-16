//
//  AABB.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/20/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "AABB.h"
bool AABB::debugToggle=true;
void AABB::DebugDraw(const Vector2D & pos )
{
    if (debugToggle==true)
    {
        
        SDL_SetRenderDrawColor(SDLRender::render, 0x00, 0x00, 0xFF, 0xFF );
        
        SDL_Rect r=this->GetSDLRect();
        r.x=pos.x;
        r.y=pos.y;
        //std::cout<<r.h;
        
        SDL_RenderDrawRect(  SDLRender::render, &r );
    }
    
}

bool AABB::IsIntersect( const AABB &aabb)const
{
    SDL_Rect rectA=this->GetSDLRect();
    SDL_Rect rectB=aabb.GetSDLRect();
    
    if (SDL_HasIntersection(&rectA, &rectB))
    {
        return true;
    }
    return false;

}
bool AABB::IsIntersect(SDL_Rect rect)
{
    
    SDL_Rect rectA=this->GetSDLRect();
    
    
    if (SDL_HasIntersection(&rectA, &rect))
    {
        return true;
    }
    return false;
    
}
bool AABB::IsContainPoint(Vector2D &points)
{
    return (points.x>=x&&points.y>=y&&points.x<=x+w&&points.y<=y+h);
    
}
const Vector2D & AABB::GetCenter()
{
    
    //Vector2D center =  ;
    return Vector2D(x+(w/2),y+(h/2));
}
int  AABB::GetTop()const
{
    return y;
}
int  AABB::GetBottom()const
{
    return y+h;
}
int  AABB::GetRight()const
{
    return x+w;
}
int  AABB::GetLeft()const
{
    return x;
}
bool AABB::IsContain(const AABB &aabb)const
{
    return
    aabb.GetTop()>this->GetTop()&&
    aabb.GetBottom()<this->GetBottom()&&
    aabb.GetLeft()>this->GetLeft()&&
    aabb.GetRight()<this->GetRight();
    
}
bool AABB::IsContain (ICollider * collider)
{
    if (collider->GetType() == RECTANCLE)
    {
        
        return IsContain(*static_cast<AABB*>(collider));
    }
    
    else
        return false;
}
 void AABB::CreatWithDrawable(Vector2D & pos ,IDrawable *drawable)
{
    w=drawable->GetRect().w;
    h=drawable->GetRect().h;
    x=pos.x;
    y=pos.y;
}
