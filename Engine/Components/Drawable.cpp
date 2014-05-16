//
//  Drawable.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 1/24/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "Drawable.h"
Drawable::Drawable(std::string name)
{
  _texture=TextureManager::GetInstance()->GetTexture(name);
}
Drawable::Drawable()
{
  
    _texture=NULL;
    
    _objRect.w=0;
    _objRect.h=0;
//
    _objRect.x=0;
    _objRect.y=0;
    

}

Drawable::Drawable(SDL_Texture *texture)
{
    
    assert(texture!=NULL);
    
    _texture=texture;
    
    SDL_QueryTexture(_texture,NULL, NULL, &_width, &_height);
    
    
    //_sceneNode = sceneNode;
    
//    _sceneNode.GetAABB().w = _width;
//    _sceneNode.GetAABB().h = _height;
    
    _objRect.w=_width;
    _objRect.h=_height;
    
    //owner->GetSceneNode().GetAABB().w=_width;
    
    
}
 void Drawable::Draw(Vector2D& pos)
{
    
    _objRect.x = pos.x;
    _objRect.y = pos.y;
    
    _objRect.w=_width;
    _objRect.h=_height;
    
    SDL_RenderCopy(SDLRender::render, _texture, NULL, &_objRect);
}


Drawable::~Drawable()
{
    if (_texture!=NULL)
    {
        SDL_DestroyTexture(_texture);
    }
}
void Drawable::SetWidth(int width)
{
    _objRect.w=width;
};
void Drawable::SetHeight(int height)
{
    _objRect.h=height;
    
};
int Drawable::GetWidth()
{
    return _objRect.w;
};
int Drawable::GetY()
{
    return _objRect.h;
};

void Drawable::SetTexture( SDL_Texture * texture)
{
    if (texture!=NULL)
    {
        _texture=texture;
    }

    SDL_QueryTexture(_texture,NULL, NULL, &_width, &_height);
    _objRect.w = _width;
    _objRect.h = _height;

    
}
SDL_Rect Drawable::GetRect()
{
    return _objRect;
}
void Drawable::SetRect(SDL_Rect newRect)
{
    _objRect=newRect;
}

