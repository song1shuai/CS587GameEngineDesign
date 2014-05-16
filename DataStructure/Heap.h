//
//  Heap.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/7/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_Heap_h
#define CS587_ShuaiSong_Heap_h
#include "DynamicArray.h"

template<typename T>
class Heap
{
private:
    
    int                     _count;         // the number of object in the heap
    DynamicArray<T>         _arrayHeap;     // the array use of store the object
    int (*Compare)(T,T);                    // the compare function for heap
    
public:
    
    Heap(int (*ComparePtr)(T,T)):Compare(ComparePtr)
    {
        _count=0;
        _arrayHeap.InsertAtLast(0);
    };
    ~Heap(){};
    void Insert(T value1);
    
    T PopMax();
    
    bool IsEmpty();
    int GetLength();
    
    T i(int a)
    {
        return _arrayHeap[a];
    }
};

template<typename T>
void Heap<T>::Insert(T value1)
{
    _count++;
    
    
    _arrayHeap.InsertAtLast(value1);
    
    int childIndex = _count;
    int parentIndex = _count/2;
    
    while (parentIndex>0)
    {
        if (Compare(value1,_arrayHeap[parentIndex])>0)
        {
            _arrayHeap[childIndex] = _arrayHeap[parentIndex];
            childIndex = parentIndex;
            parentIndex/=2;
        }
        else
        {
            break;
        }
        
    }
    
    _arrayHeap[childIndex]=value1;
    
  
}
template<typename T>
bool Heap<T>::IsEmpty()
{
    return _count;
}

template<typename T>
int Heap<T>::GetLength()
{
    return _count;
}


template<typename T>
T  Heap<T>::PopMax()
{
 T  maxValue=_arrayHeap[1];
    
    assert(_count>=1);
    
    _arrayHeap[1]=_arrayHeap[_count];
    
    int parentIndex = 1;
    int childIndex = 2;
    T tempValue=_arrayHeap[_count];
    
    while (childIndex<_count)
    {
        if (childIndex <_count-1)
        {
            
            if (Compare(_arrayHeap[childIndex],_arrayHeap[childIndex+1])<0)
            {
                childIndex++;
            }
            
        }
        
        if (Compare(_arrayHeap[parentIndex],_arrayHeap[childIndex])<0)
        {
            _arrayHeap[parentIndex]=_arrayHeap[childIndex];
            _arrayHeap[childIndex]=tempValue;
            parentIndex=childIndex;
            childIndex*=2;
            
        }
        
        else
        {
            break;
        }
    }
    _count--;
    

    return maxValue;
}
#endif
