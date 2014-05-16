//
//  BitArray.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 3/17/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_BitArray_h
#define CS587_ShuaiSong_BitArray_h
#include <iostream>
class BitArray
{
protected :
    
    
public:
    int _length;
    unsigned long int * _bArray;
    BitArray();
    void Reserve(int newCapacity);
    BitArray(int length);
    bool operator [](int index);
    void Set(int index ,bool value);
    void SetBit(int bit);
    void Reset();                   //set all the bit to zero
    ~BitArray();
};


#endif
