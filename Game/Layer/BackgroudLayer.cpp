//
//  BackgroudLayer.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/2/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "BackgroudLayer.h"
//BackgroudLayer::BackgroudLayer(std::string name)
//{
//    Drawable = new Drawable(name);
//}

void BackgroudLayer::Render()
{
    
   Vector2D _pos =this->Getposition();
    
    Update();
    for (int i = 0; i < 6; i++)
    {
        

    
        SDL_RenderCopyEx(SDLRender::render, _Bgs[i].image, &_Bgs[i].src1, &_Bgs[i].dest1, 0, 0, SDL_FLIP_NONE);
        SDL_RenderCopyEx(SDLRender::render,_Bgs[i].image, &_Bgs[i].src2, &_Bgs[i].dest2, 0, 0, SDL_FLIP_NONE);

    }
    this->Move(Vector2D(1, 0));
   
    // _bgImage->Draw(_pos);
    
}
void BackgroudLayer::Update()
{
    for (int i=0; i<6; i++)
    {
        
    
        if (_Bgs[i].src1.x+SDLRender::screenWidth>=_bgWidth)
        {
            // increase first rec size
            _Bgs[i].src1.x+=_Bgs[i].speed;
            _Bgs[i].src1.w-=_Bgs[i].speed;
            _Bgs[i].dest1.w-=_Bgs[i].speed;
        
            // shrink the second rec
            _Bgs[i].src2.w+=_Bgs[i].speed;
            _Bgs[i].dest2.w+=_Bgs[i].speed;
            _Bgs[i].dest2.x-=_Bgs[i].speed;
        
            if (_Bgs[i].dest2.x<=0)
            {
            
            
                //ResetRect();
                _Bgs[i].Reset();

            }
        
        
        }
        else
        {
            _Bgs[i].src1.x +=_Bgs[i].speed;

        }
    
    }
    

}
void BackgroudLayer::ResetRect()
{
    _src1.x = 0;
    _src1.y = 0;
    _dest1.x =0;
    _dest1.y =0;
    
    _src1.w = _dest1.w = SDLRender::screenWidth;
    _src1.h = _dest1.h = SDLRender::screenHeight;
    
    
    
    _src2.x = 0;
    _src2.y = 0;
    _src2.w = 0;
    _src2.h = SDLRender::screenHeight;
    
    _dest2.x =SDLRender::screenWidth;
    _dest2.y =0;
    _dest2.w = 0;
    _dest2.h = SDLRender::screenHeight;
}

BackgroudLayer::BackgroudLayer()
{
    

    //_bgImage.SetTexture(bg);
   // _bgImage = new Drawable(bg);

    

};
void BackgroudLayer::Init()
{
    _speed = 2;
    
    for (int i = 0 ; i < 6; ++i)
    {
        //        _Bgs[i].src1.x=0;
        //        _Bgs[i].src1.y=0;
        //        _Bgs[i].src1.w=SDLRender::screenWidth;
        //        _Bgs[i].src1.h=SDLRender::screenHeight;
        //
        //        _Bgs[i].dest1.x=0;
        //        _Bgs[i].dest1.y=0;
        //        _Bgs[i].dest1.w=SDLRender::screenWidth;
        //        _Bgs[i].dest1.h=SDLRender::screenHeight;
        //
        //        _Bgs[i].src2.x=0;
        //        _Bgs[i].src2.y=0;
        //        _Bgs[i].src2.w=0;
        //        _Bgs[i].src2.h=SDLRender::screenHeight;
        //
        //        _Bgs[i].dest2.x=SDLRender::screenWidth;
        //        _Bgs[i].dest2.y=0;
        //        _Bgs[i].dest2.w=0;
        //        _Bgs[i].dest2.h=SDLRender::screenHeight;
        _Bgs[i].Reset();
        _Bgs[i].speed=i+1;
    }
    
    bg =  TextureManager::GetInstance()->GetTexture("background1");
    SDL_QueryTexture(bg,NULL, NULL, &_bgWidth, &_bgheight);
    
    _Bgs[0].image = TextureManager::GetInstance()->GetTexture("background1");
    _Bgs[1].image = TextureManager::GetInstance()->GetTexture("background2");
    _Bgs[2].image = TextureManager::GetInstance()->GetTexture("background3");
    _Bgs[3].image = TextureManager::GetInstance()->GetTexture("background4");
    _Bgs[4].image = TextureManager::GetInstance()->GetTexture("background5");
    _Bgs[5].image = TextureManager::GetInstance()->GetTexture("background6");
    
    
    ResetRect();
    this->AddChild(this);
}