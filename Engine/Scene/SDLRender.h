//
//  SDLRender.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/20/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__SDLRender__
#define __CS587_ShuaiSong__SDLRender__

#include <iostream>
#include "SDLRender.h"
#include <SDL2/SDL.h>


class SDLRender
{
public:
    ~SDLRender();
     SDLRender();
     static int              screenWidth;
     static int              screenHeight;
     static int              FPS;
     static SDL_Window*      window;        //The SDL_window object
     static SDL_Renderer*    render;        //The SDL_Renderer object
     static void ClearScreen();
     static void PresentToScreen();
    
     bool SetupRenderScene();
     void CleanUp();
};
#endif /* defined(__CS587_ShuaiSong__SDLRender__) */
