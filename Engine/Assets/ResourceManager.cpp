//
//  ResourceManager.cpp
//  CS/Users/shuaisong/Desktop/CS587_ShuaiSong/CS587_ShuaiSong/Engine/Debug587_ShuaiSong
//
//  Created by shuai song on 3/28/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "ResourceManager.h"
ResourceManager *  ResourceManager::_instance = NULL;

JValue *ResourceManager::GetJson(std::string name)
{
    
    return *_jsonMap.Find(name);
}
void ResourceManager::Load()
{
    JValue * gameDate = JsonParser::ParseFile("Config/config.json");
    JValue &resource = (*gameDate)["Resource"];
    
    for (int i = 0; i < resource.GetLength(); ++i)
    {
        
        JValue * levelData = JsonParser::ParseFile(resource[i]["location"].ToString().c_str());
        
        _metaData.InsertAtLast(levelData);
        //_metaData.InsertAtFirst(levelData);
        
    }
    LoadNext();
}
void ResourceManager::LoadNext()
{
    DebugManager::GetInstance()->CreatChannel("Resource");
    
    JValue * levelData =  _metaData.GetFrist();
    //
    JValue &level = (*levelData)["Level"];
    //
    for (int i = 0; i < level.GetLength(); i++)
    {
        std::string type = level[i]["type"].ToString();
         std::string name = level[i]["name"].ToString();
        if (type!="sprite")
        {
            
            
           
            std::string location =  level[i]["location"].ToString();
            if (type == "image")
            {
                if (TextureManager::GetInstance()->LoadTexture(location, name))
                {
                    DEBUGCLOG("Resource","%s%s%s%s",type.c_str(),":",name.c_str(),"...load sucess!!!");
                    continue;
                } ;
                
                DEBUGCLOG("Resource","%s%s%s%s",type.c_str(),":",name.c_str(),"...load error!!!");
                
            }
            
            if (type == "json")
            {
                JValue* jsonObj =  JsonParser::ParseFile(location.c_str());
                if (jsonObj!=NULL)
                {
                    _jsonMap.Insert(level[i]["name"].ToString(), jsonObj);
                    jsonObj = NULL;
                    DEBUGCLOG("Resource","%s%s%s%s",type.c_str(),":",name.c_str(),"...load sucess!!!");
                    continue;
                }
                DEBUGCLOG("Resource","%s%s%s%s",type.c_str(),":",name.c_str(),"...load error!!!");
                
            }
        }
        else
        {
            std::string imageLocation = level[i]["image"].ToString();
            JValue &sprite = level[i]["sprite"];
            
            if (TextureManager::GetInstance()->LoadTexture(imageLocation, name))
            {
                DEBUGCLOG("Resource","%s%s%s%s",type.c_str(),":",name.c_str(),"...load sucess!!!");
                
            };
            
            for (int i = 0;i <sprite.GetLength() ; i++)
            {
                std::string actionname = sprite[i]["name"].ToString();
                std::string jsonlocation = sprite[i]["json"].ToString();
                JValue* jsonObj =  JsonParser::ParseFile(jsonlocation.c_str());
                if (jsonObj!=NULL)
                {
                    DEBUGCLOG("Resource","%s%s%s%s",type.c_str(),":",actionname.c_str(),"...load sucess!!!");
                }
                
                SDL_Texture *image = TextureManager::GetInstance()->GetTexture(name);
                Sprite * sprite= new Sprite(jsonObj,image);
                _spriteMap.Insert(actionname, sprite);
                //image=NULL;
                //sprite=NULL;
                
            }
        }
    }
}

SDL_Texture * ResourceManager::GetTexture(std:: string name)
{
    
    return TextureManager::GetInstance()->GetTexture(name);
}
Sprite * ResourceManager::GetSprite(std::string name)
{
    DEBUGLOG("%s",name.c_str());
    
    
    Sprite * sprite =(*_spriteMap.Find(name));
    
    return sprite ;
}