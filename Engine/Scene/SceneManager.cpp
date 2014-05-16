//
//  SceneManager.cpp
//  sdl
//
//  Created by shuai song on 1/21/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "SceneManager.h"
//SDL_Window*SceneManager:: _window=NULL;
//SDL_Renderer*SceneManager::_render=NULL;
SceneManager * SceneManager::_instance = NULL;


SceneManager::~SceneManager()
{
    
}

bool SceneManager::Init()
{

    
    if(!_SDLRender.SetupRenderScene())
    {
        return false;
    }
    
    
   //_root.SetPos(Vector2D(0,0));
    LayerNode * rootLayer = new  LayerNode(NULL,NULL);
    rootLayer->SetZOrder(-1);
    rootLayer->SetName("root");
    // rootLayer->SetPos(Vector2D::ZERO);
    _layerlist.InsertAtLast(rootLayer);
    
    _quadtree.CreatQuadTree(0, 0, 800, 800);
    

    return true;
    
}

void SceneManager::Render()
{

   SDLRender::ClearScreen();
    
    for (int i =0; i <_layerlist.GetLength(); i++)
    {
        //_layerlist[i]->Getposition().x--;
        _layerlist[i]->Draw();
        
    }
    

   // _quadtree.DebugDraw();
    SDLRender::PresentToScreen();
    
   
}

void SceneManager::AddToSence(Actor *RenderObject)
{
    assert(RenderObject!=NULL);
    
    //_drawList.InsertAtLast(RenderObject);
    
   
}

void SceneManager::AddTickable(ITickable * tickObject)
{
 
    assert(tickObject!=NULL);
    
    _tickList.InsertAtLast(tickObject);
  
    
}
void SceneManager::Tick(float dt)
{
    //Iterate all tickable object in the ticklist then tick it
    
    for (int i=0; i<_tickList.GetLength(); i++)
    {
        _tickList[i]->Tick( dt);
        
    }

}

void SceneManager::Clear()
{

    
}
void SceneManager::Update()
{
   
    
    
    this->Tick(SDLRender::FPS/1000);
    this->Render();
   
}
ISceneNode * SceneManager::AddSceneNode(Actor* actor,ISceneNode *parent)
{
 
    
    ISceneNode * a =new ActorSceneNode(actor);
    return a ;
}
ISceneNode * SceneManager::AddActorToScene(Actor * actor)
{
    ActorSceneNode * actorNode =new ActorSceneNode(actor);
    _layerlist.GetLast()->AddChild(actorNode);
    
    if (actor->GetCollider()!=NULL)
    {
        
      //quadRoot->Insert(actorNode);
    }
    
    if (actor->GetPhysics()!=NULL)
    {
            actor->GetPhysics()->sceneNode=actorNode;
    }

    return actorNode;
    
    
}
LayerNode * SceneManager::AddLayer(std::string name,int zOrder)
{
    LayerNode * layer =new LayerNode();
    layer->SetName(name);
    if (zOrder == -1)
    {
       
        _layerlist.InsertAtLast(layer);
        _layerMap.Insert(name, layer);

        return layer;
    }
    else
    {
        int i;
        for ( i = _layerlist.GetLength()-1; i >0; i--)
        {
            if (_layerlist[i]->GetZorder() < zOrder)
            {
                break;
            }
        }
        if (i+1 == _layerlist.GetLength())
        {
            _layerlist.InsertAtLast(layer);
            _layerMap.Insert(name, layer);
            return layer;
        }
        _layerMap.Insert(name, layer);
        _layerlist.InsertAtIndex(i+1, layer);

  
    }
    
   
    
    return layer;
    
}

void SceneManager::AddLayer(LayerNode * layer,int zOrder)
{
    layer->SetZOrder(zOrder);
    if (zOrder == -1)
    {
        _layerlist.InsertAtLast(layer);
        
    }
    else
    {
        int i;
        for ( i = _layerlist.GetLength()-1; i >0; i--)
        {
            if (_layerlist[i]->GetZorder() < zOrder)
            {
                break;
            }
        }
        
        if (i+1 == _layerlist.GetLength())
        {
            _layerlist.InsertAtLast(layer);
            return ;
        }
        _layerlist.InsertAtIndex(i+1, layer);
    }
    
    
}
LayerNode * SceneManager::FindLayerByName(std::string name)
{

    
    LayerNode * layer = *_layerMap.Find(name);
    if (layer!=NULL)
    {
        return layer;
    }
    return NULL;

}
ISceneNode * SceneManager::AddActorToLayer(std::string name, Actor * actor)
{
    LayerNode * layer = FindLayerByName(name);
    ActorSceneNode * actorNode =new ActorSceneNode(actor);
    layer->AddChild(actorNode);
    return actorNode;
}
