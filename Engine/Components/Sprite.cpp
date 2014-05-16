//
//  Sprite.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/26/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Sprite.h"
Sprite::Sprite(JValue * config,SDL_Texture * texture)
{
    


    
   _numFrames=(*config)["frames"].GetLength();
  _frames = new Frame[_numFrames];
   
    for (int i = 0; i<_numFrames; i++)
    {
        _frames[i].id=i;
        _frames[i].rect.x=(*config)["frames"][i]["frame"]["x"].ToInt();
        _frames[i].rect.y=(*config)["frames"][i]["frame"]["y"].ToInt();
        _frames[i].rect.w=(*config)["frames"][i]["frame"]["w"].ToInt();
        _frames[i].rect.h=(*config)["frames"][i]["frame"]["h"].ToInt();
        _frames[i].name = (*config)["frames"][i]["filename"].ToString();
        
    // std::cout<< _frames[i].name <<std::endl;
    }
    _currentFrame=_startFrame=0;
    
    _speed=55;
    _lastFrameTime=0;
    
    _spriteSheet = texture;
    
}

void Sprite::Update()
{
 
}
void Sprite::Draw(Vector2D & pos)
{
    float interval= SDL_GetTicks()- _lastFrameTime;
    SDL_Rect renderQuad;
    
    if( _frames != NULL )
    {
        renderQuad.w = _frames[_currentFrame].rect.w;
        renderQuad.h = _frames[_currentFrame].rect.h;
        
        
        renderQuad.x=pos.x ;
        renderQuad.y=pos.y  ;
    }
    if (interval>=_speed)
    {
    
        _currentFrame++;
        _currentFrame%=_numFrames;
        _lastFrameTime=SDL_GetTicks();
	}
    
    //Render to screen
   
    SDL_RenderCopy(SDLRender::render, _spriteSheet, &_frames[_currentFrame].rect, &renderQuad);
    
	
}
void Sprite::Stop()
{
 
    
}
void Sprite::SetRect(SDL_Rect newRect)
{
    
}
SDL_Rect Sprite::GetRect()
{
  return   _frames[_currentFrame].rect;
}
void Sprite::SetSpeed(float speed)
{
    _speed = speed;
}
void Sprite::SetTexture( SDL_Texture * texture)
{
    _spriteSheet = texture;
}