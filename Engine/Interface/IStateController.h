//
//  IStateController.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__IStateController__
#define __CS587_ShuaiSong__IStateController__

#include <iostream>
class IStateController
{
public:
    virtual void ChangeToState(std::string name)=0;
};
#endif /* defined(__CS587_ShuaiSong__IStateController__) */
