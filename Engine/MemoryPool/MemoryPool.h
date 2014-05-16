//
//  MemoryPool.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/20/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__MemoryPool__
#define __CS587_ShuaiSong__MemoryPool__

#include <iostream>
//class MemoryPool;


template<typename T ,int Size = 50>
class MemoryPool
{
    
    
    
private:

    union Chunk                 // The basic unit use of object
    {
        Chunk * next;
        char buffer[sizeof(T)];
    };
    
    struct Block                // A block of memeoy includes fix size chunks
    {
        Block * next;
        Chunk  Chunks[Size];
    };
      Block * _blockHead ;         // The head node of the block
      Chunk * _chunkHead ;         // The head node of the chunk
    
public:
    MemoryPool():_blockHead(NULL),_chunkHead(NULL){};
    //MemoryPool();
    ~MemoryPool()
    {
        while (_blockHead!= NULL)
        {
            
            // delete all the block in the block list
            
            Block * tmpBlock = _blockHead;
            _blockHead =_blockHead->next;
            delete tmpBlock;
        }
    }
    T *Allocate()
    {
        if (_chunkHead == NULL)
        {
            // If there is no free chunks, allocate a block memory
            // add to the head of block list .
            
            Block * newBlock =  new Block();
            newBlock->next = _blockHead;
            _blockHead = newBlock;
            
            for (int i = 0; i< Size ; ++i)
            {
                // make a list of new chunks in the block.
                _blockHead ->Chunks[i].next = &(_blockHead ->Chunks[i+1]);
            }
            
            // set the last chunk in the chunk list to null
            _blockHead->Chunks[Size -1].next = NULL;
            _chunkHead = &(_blockHead->Chunks[0]);
        }
        
        
        // reture the first free chunk
        
        Chunk * newchunk = _chunkHead;
        _chunkHead = _chunkHead->next;
        
        return  reinterpret_cast<T*>(newchunk);
    }
    
    void Free(T * object)
    {
        
        // add the free chunk back to chunklist
        Chunk * returnChunk =  reinterpret_cast<Chunk *>(object);
        returnChunk->next = _chunkHead;
        _chunkHead = returnChunk;
    }


};



#endif /* defined(__CS587_ShuaiSong__MemoryPool__) */
