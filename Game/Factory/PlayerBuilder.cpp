//
//  PlayerBuilder.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/11/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "PlayerBuilder.h"
GameActor* PlayerBuilder::GetNewActor()
{
    assert(_playerActor);
    return  _playerActor;
}
void PlayerBuilder::BuildActor(ActorData * data)
{
    /*
     config the playe actor
     */
    
    
    _playerActor = new GameActor();
    Sprite * sprite = ResourceManager::GetInstance()->GetSprite(data->asset);
    PlayerPhysics *playerPhysics = new PlayerPhysics(_playerActor);
    
    
    playerPhysics->speed = data->jumpSpeed;
    playerPhysics->direction = data->direction;
    playerPhysics->acceleration = data->acceleration;
    
    AABB * aabb = new AABB();
    
    _playerActor->SetPosition(data->position);
    _playerActor->data = *data;
    _playerActor->SetDrawable(sprite);
    _playerActor->SetPhysics(playerPhysics);
    _playerActor->SetCollider(aabb);
    
    sprite=NULL;
}
PlayerBuilder::~PlayerBuilder()
{
    if (_playerActor!=NULL)
    {
        delete _playerActor;
    }
    
    _playerActor=NULL;
}
 void PlayerBuilder::AddToScene()
{
    SceneManager::GetInstance()->AddActorToScene(_playerActor);
}