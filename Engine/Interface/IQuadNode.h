//
//  IQuadNode.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 4/17/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_IQuadNode_h
#define CS587_ShuaiSong_IQuadNode_h
class ISceneNode;
class IQuadNode
{
/*
 This interface use for update the sceneNode in the quadtree
 */
public:
    virtual void RemoveObject(ISceneNode *sceneNode)=0;
    virtual void Update(ISceneNode *sceneNode)=0;
    
};


#endif
