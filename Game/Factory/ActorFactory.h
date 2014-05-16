//
//  ActorFactory.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/10/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__ActorFactory__
#define __CS587_ShuaiSong__ActorFactory__

#include <iostream>
#include "IBuilder.h"
#include "HashMap.h"
class ActorFactory
{
private:
    HashMap<IBuilder*> _builderMap;
public:
    void ReisterType(std:: string typeName ,IBuilder *builder);
    Actor * GetActor(std::string name);
    
};
#endif /* defined(__CS587_ShuaiSong__ActorFactory__) */
