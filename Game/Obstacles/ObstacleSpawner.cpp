//
//  ObstacleSpawner.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/23/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "ObstacleSpawner.h"
void ObstacleSpawner::Tick(float dt)
{
    

    
}
void ObstacleSpawner::RegisterObstacle(Obstacles * obstacle)
{
 
    SceneManager::GetInstance()->AddActorToScene(obstacle);
}
void ObstacleSpawner::GenerateObstacle(const Vector2D & pos,int i)
{
    
    
    
    Obstacles * obstacle = _obstacleArray[i]->Clone();
    
    Vector2D scenePos = Vector2D::ZERO;
    scenePos.x = pos.x;
    scenePos.y = pos.y-2*obstacle->GetCenter().y;
    
    obstacle->SetPosition(scenePos);
    SceneManager::GetInstance()->AddActorToLayer("obstacle", obstacle);
    _nextpos.x+=2*obstacle->GetCenter().x;
    
}
Obstacles *ObstacleSpawner::GetObstacle(std::string name)
{
   return  *_obstacles.Find(name);
    
}
ObstacleSpawner::ObstacleSpawner(GameActor* player)
{
    
     Deserialize();
    _nextpos.x = player->GetPosition().x+2*player->GetCenter().x;
    _nextpos.y = player->GetPosition().y+2*player->GetCenter().y;
    
    /*
     TODO:
     This part should be in the tick generate the obstactle base 
     On It's weight and the hard of the level stage
     Now just random generate some obstacle for test;
     */
    
    
    for (int i = 0; i < 100; i++)
    {
        _nextpos.x+=Random(100,150);
        
        int j= Random(4,1);
        GenerateObstacle(_nextpos,j-1);

    }
    
    
    
}
void ObstacleSpawner::Deserialize()
{
    JValue* obstacleData = ResourceManager::GetInstance()->GetJson("ObstacleConfig");
    JValue & obstacleArray =  (*obstacleData)["obstacles"];
    
    _numOfObtacles =  obstacleArray.GetLength();
    
    for (int i = 0; i <_numOfObtacles;i++ )
    {
        std::string name = obstacleArray[i]["name"].ToString();
        SDL_Texture * texture =
        ResourceManager::GetInstance()->GetTexture(name);
        Drawable * drawable = new Drawable();
        drawable->SetTexture(texture);
        AABB * aabb = new AABB();
        aabb->SetRect(drawable->GetRect());
        
        Obstacles * newObstacle = new  Obstacles();
        newObstacle->SetCollider(aabb);
        newObstacle->SetDrawable(drawable);
        newObstacle->weight = obstacleArray[i]["weight"].ToInt();
        
        _obstacleArray.InsertAtLast(newObstacle);
    }
    
    DEBUGLOG("%s","ObstacleSpawner init success");
}
