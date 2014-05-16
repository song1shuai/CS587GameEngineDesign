//
//  Sence.h
//  sdl
//
//  Created by shuai song on 1/21/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __sdl__Sence__
#define __sdl__Sence__

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "DynamicArray.h"
#include "ITickable.h"
#include "Actor.h"
#include <assert.h>
#include "SDLRender.h"
#include "QuadTree.h"
#include "JValue.h"
#include "ActorSceneNode.h"
#include "ISceneNode.h"
#include "LayerNode.h"
#include "QuadNode.h"
#include "QuadTree.h"

typedef DynamicArray<LayerNode*> LAYERLIST;
typedef HashMap<LayerNode*> LAYERMAP;

class SceneManager
{
private:
    
    
  
    SDLRender _SDLRender;
    
    DynamicArray<ITickable*>    _tickList;      //The tick  list
    
    LAYERLIST _layerlist;                       //The list of layer
    LAYERMAP  _layerMap;                        //The layer map
    
    static SceneManager * _instance;
    
    SceneManager(){};
public:

    /*
     should be private put it hear just for test
     */
    
    QuadTree  _quadtree;
    
    static SceneManager * GetInstance()
    {
        if (_instance == NULL)
        {
          _instance = new SceneManager();
        }
        
        return _instance;
    }
    ~SceneManager();
    
    /**
     *@brief Add a actor to draw list;
     *
     *prama  the actor reference the user want to add.
     */
    
    void AddToSence(Actor* actor);
    
    /**
     *@brief Add a ITickable object to tick list;
     *
     *prama The ITickable reference the user want to add.
     */
    
    void AddTickable(ITickable* itickable);
    
    /**
     *@brief Remove a actor from draw list;
     *
     *prama  the actor reference the user want to remove.
     */
    
    void RemoveFromSence(Actor* actor);
    
    /**
     *@brief Remove a ITickable object from tick list;
     *
     *prama The ITickable reference the user want to remove.
     */
    
    void RemoveFromTickable(ITickable* itickable);
    
    /**
     *@brief Get the reference of SDLRender;
     *
     */
    
    //SDL_Renderer* GetSDLRender();
    
    /**
     *@brief Initialize The SDL context.
     *
     */
    
    bool Init();
    
    /**
     *@brief Draw the actor which in the draw list to the screen;
     *
     */
    
    void Render();
    
    /**
     *@brief Run all the iticables which int the tick list;
     *
     */
    
    void Tick(float dt);
    
    /**
     *@brief Clear all the actor on the screen.
     *
     */
    
    void Clear();
    /**
     *@brief Do render and tick.
     *
     */
    
    void Update();
    
    void LoadSceneFromJson(JValue &scene){};
    ISceneNode * AddSceneNode(Actor* actor,ISceneNode *parent=NULL );
    ISceneNode * AddActorToLayer(std::string name, Actor * actor);
    ISceneNode * AddActorToScene(Actor * actor);
    LayerNode * AddLayer(std::string name,int zOrder=-1);
    LayerNode * GetLayer(std::string name);
    void AddLayer(LayerNode *,int zOrder);
    LayerNode * FindLayerByName(std::string name);
    
};

#endif /* defined(__sdl__Sence__) */
