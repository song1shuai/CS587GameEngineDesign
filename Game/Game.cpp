#include "Game.h"

Game::Game()
{
    
}
Game::~Game()
{
  
    
}
void Game::Run()
{
  
    while (!_isStop)
    {
     
        
        _lastFrameTime=SDL_GetTicks();
        
        InputManager::GetInstance()->Update();
        
        
        EventBus::GetInstance()->Update();
        SceneManager::GetInstance()->Render();
        SceneManager::GetInstance()->Tick(_frameTime/1000.f);
        _frameTime=SDL_GetTicks()-_lastFrameTime;
        
        
        if (_frameTime<1000.f/SDLRender::FPS)
        {
            _frameTime = 1000.F/SDLRender::FPS -_frameTime;
         
            SDL_Delay((int)(_frameTime));
        
        }
        
       // EventBus::GetInstance()->Update();
    }
    
    
}

bool Game::InitEngine()
{
    /**
     *  Init the game content
     *
     */
    
    _isStop=false;
    
   // _gameSence = new SceneManager();
    
    
    if (!SceneManager::GetInstance()->Init())
    {
        return false;
    }
    
      ResourceManager::GetInstance()->Load();


  
     return true;
}



