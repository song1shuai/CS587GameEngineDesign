//
//  SDLRender.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/20/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "SDLRender.h"
int SDLRender::screenWidth = 800;
int SDLRender::screenHeight = 400;
SDL_Window* SDLRender::window = NULL;        //The SDL_window object
SDL_Renderer*  SDLRender::render =NULL;       //The SDL_Renderer object
int SDLRender::FPS=60;
SDLRender::SDLRender()
{

}
bool SDLRender::SetupRenderScene()
{
    //Initialize SDL
    
    if(SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
        std::cout<<"SDL could not initialize!"<<SDL_GetError()<<std::endl;
        return false ;
	}
    
    //Create window
    
    window = SDL_CreateWindow( "Test",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               screenWidth,
                               screenHeight,
                               SDL_WINDOW_SHOWN
                               );
    if(window == NULL)
    {
        std::cout<<"Window could not be created!"<<SDL_GetError()<<std::endl;
        return false;
    }
    
    //Creat Renderer
    
    render=SDL_CreateRenderer(window, -1, 0);
    
    if(render == NULL)
    {
        std::cout<<"_render could not be created!"<<SDL_GetError()<<std::endl;
        return false;
    }
    

    
    
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    
    return true;
}
SDLRender::~SDLRender()
{
    CleanUp();
}
void SDLRender::CleanUp()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}
void SDLRender::ClearScreen()
{
    SDL_SetRenderDrawColor(SDLRender::render, 0, 0, 0, 0);
    SDL_RenderClear(SDLRender::render);
}
void SDLRender::PresentToScreen()
{
     SDL_RenderPresent(SDLRender::render);
}