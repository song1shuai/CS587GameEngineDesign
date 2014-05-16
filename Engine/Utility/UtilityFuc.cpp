//
//  UtilityFuc.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/12/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "UtilityFuc.h"

int compare(IEvent*e1, IEvent * e2)
{
    return e2->stamp-e1->stamp;
}


int GetUniqueID()
{
    
    ID++;
    return ID;
}
int Random( int max, int min )
{
	return (min + ( rand() % max ) );
}