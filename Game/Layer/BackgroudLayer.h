//
//  BackgroudLayer.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/2/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__BackgroudLayer__
#define __CS587_ShuaiSong__BackgroudLayer__

#include <iostream>
#include "LayerNode.h"
#include "IDrawable.h"
#include "ITickable.h"
#include "TextureManager.h"
#include "Drawable.h"
#include "SDLRender.h"
/*
 TODO
 a custom layer , should be date driven ;
 now just hard coding for test.
 */



class BackgroudLayer:public LayerNode
{
    struct ParallaxBg
    {
        SDL_Texture * image;
        SDL_Rect src1;
        SDL_Rect dest1;
        SDL_Rect src2;
        SDL_Rect dest2;
        
        float speed;
        
        void Reset()
        {
            src1.x=0;
            src1.y=0;
            src1.w=SDLRender::screenWidth;
            src1.h=SDLRender::screenHeight;
            
            dest1.x=0;
            dest1.y=0;
            dest1.w=SDLRender::screenWidth;
            dest1.h=SDLRender::screenHeight;
            
            src2.x=0;
            src2.y=0;
            src2.w=0;
            src2.h=SDLRender::screenHeight;
            
            dest2.x=SDLRender::screenWidth;
            dest2.y=0;
            dest2.w=0;
            dest2.h=SDLRender::screenHeight;
        }
    };
    
private:
    SDL_Texture * bg;
    
    int _bgWidth;
    int _bgheight;
    
    float _speed;
    SDL_Rect _src1;
    SDL_Rect _dest1;
    SDL_Rect _src2;
    SDL_Rect _dest2;
    void ResetRect();
    ParallaxBg _Bgs[6];
public:
    BackgroudLayer();
   
    void Init();
    void Update();
    void Render();
};
#endif /* defined(__CS587_ShuaiSong__BackgroudLayer__) */
