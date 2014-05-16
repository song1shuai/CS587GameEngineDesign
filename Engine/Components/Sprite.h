//
//  Sprite.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/26/14.
//  Copyright (c) 2014 shuai song. All rights reserved.


#ifndef __CS587_ShuaiSong__Sprite__
#define __CS587_ShuaiSong__Sprite__

#include <iostream>
#include "IDrawable.h"
#include <SDL2/SDL.h>
#include "TextureManager.h"
#include "JsonParser.h"
#include "SDLRender.h"
#include "JValue.h"

 struct Frame
{
    std::string name;
    SDL_Rect  rect;
    int id;
};

class Sprite:public IDrawable
{
    
private:
    
    
    int _lastFrameTime;
    int _currentFrame;
    int _startFrame;
    int _width;
    int _height;
    int _speed;
    SDL_Texture * _spriteSheet;
    
    Frame *_frames;
    int _numFrames;
    
public:
    Sprite(){};
    Sprite(JValue * config,SDL_Texture * texture);
    void Update();
    void Draw(Vector2D & pos);
    void Stop();
    SDL_Rect GetRect();
    void SetRect(SDL_Rect newRect);
    void SetSpeed(float speed);
    void SetTexture( SDL_Texture * texture);
    
};

#endif /* defined(__CS587_ShuaiSong__Sprite__) */
