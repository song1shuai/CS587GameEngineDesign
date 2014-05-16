//
//  Camera.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/26/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__Camera__
#define __CS587_ShuaiSong__Camera__

#include <iostream>
#include "Vector2D.h"
#include "Actor.h"
#include "ICamera.h"
class Camera:public ICamera
{
  
public:
    
   virtual void SetPosition(const Vector2D & pos);
   virtual Vector2D &GetPosition();
private:
    

    Vector2D _position;
};
#endif /* defined(__CS587_ShuaiSong__Camera__) */
