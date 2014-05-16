//
//  ActorFactory.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/10/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "ActorFactory.h"
void ActorFactory::ReisterType(std:: string typeName ,IBuilder *builder)
{
 
    _builderMap.Insert(typeName, builder);
    
}

Actor * ActorFactory::GetActor(std::string name)
{
    IBuilder*  builder= *_builderMap.Find(name);
    builder->BuildActor();
    return builder->GetNewActor();
}