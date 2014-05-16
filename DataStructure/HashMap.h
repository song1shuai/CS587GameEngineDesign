//
//  HashMap.h
//  CS587
//
//  Created by shuai song on 1/18/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587__HashMap__
#define __CS587__HashMap__

#include <iostream>
#include <string>
#include "DynamicArray.h"
#define TABLESIZE 10


template<typename T>
struct Entry
{
    std::string key;
    T data;
};

template<typename T>
class HashMap
{
    typedef  Entry<T>                           Entry;
    typedef  DynamicArray<DynamicArray<Entry>>  MAP;
    typedef  DynamicArray<std::string>          KeyList;
    
private:
    
    MAP         _map;                           // The map use to store the entry
    KeyList     _keys;                          // The key list
    int         _count;                         // The number of entries in the map
    int         _HashFunc(std::string);         // The hash function
    

public:
    
    HashMap():_map(TABLESIZE),_count(0){};
    ~HashMap();
    
    HashMap(const HashMap<T> & targetMap)
    {
        _keys=targetMap._keys;
        _map =targetMap._map;
        _count=targetMap._count;
    }
    /**
     * @brief Insert a key/data value into map
     *
     * @prama the key of the value
     * @prama the value your want to insert
     */
    
    void Insert(std::string key ,T data);
    
    /**
     * @brief Use a specific key to find a date stored in map
     *
     * @prama the key of the value
     */
    
    T* Find(std::string key);
    
    /**
     * @brief Use remove a data store in map by specific key
     *
     * @prama The key of the data
     */
    
    void Remove(std::string key);
    
    /**
     * @brief Return all keys
     *
     */
    
    DynamicArray<std::string> &GetAllKey();
    
    T *operator [] (const std::string  key)
    {
        return this->Find(key);
    }
    
};

//template<typename T>


template<typename T>
int HashMap<T>::_HashFunc(std::string key)
{
    // BKDR Hash Function
    
    unsigned int seed = 131;
    unsigned int hash = 0;
    
    
    const char * str = key.data();
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    
    return (hash & 0x7FFFFFFF)%TABLESIZE;
}

template<typename T>
HashMap<T>::~HashMap()
{
    
    
}

template<typename T>
void HashMap<T>::Insert(std::string key ,T data)
{
   //Generate a new entry and insert it into hashmap
    
    Entry newEntry;
    
    newEntry.data=data;
    newEntry.key=key;
    
    int index=_HashFunc(key);
    _map[index].InsertAtLast(newEntry);
    _keys.InsertAtLast(key);


    _count++;
}

template<typename T>
T* HashMap<T>::Find(std::string key)
{
    int index=_HashFunc(key);

    for (int i=0; i<_map[index].GetLength(); ++i)
    {
        std::string tmp=_map[index][i].key;
        if (tmp==key)
        {
            return &_map[index][i].data;
        }
    }
    
    return nullptr;
}

template<typename T>
void HashMap<T>::Remove(std::string key)
{
    int index=_HashFunc(key);
    int lenght= _map[index].GetLength();
    
    //Remove the entry from hashmap
    
    for (int i=0; i<lenght; ++i)
    {
        if (_map[index][i].key==key)
        {
            _map[index].RemoveAtIndex(i);
        }
    }
    
    //Remove the key from key list.
    
    for (int i=0; i<_keys.GetLength(); ++i)
    {
        if (_keys[i]==key)
        {
            _keys.RemoveAtIndex(i);
        }
    }
    
}

template<typename T>
DynamicArray<std::string>& HashMap<T>::GetAllKey()
{
    for(int i=0 ; i<_keys.GetLength();i++)
    {
        std::cout<< _keys[i]<<std::endl;
    }
    
    return _keys;
}




#endif /* defined(__CS587__HashMap__) */
