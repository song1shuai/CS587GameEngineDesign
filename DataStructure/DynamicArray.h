//
//  DynamicArray.h
//  CS587
//
//  Created by shuai song on 1/17/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587__DynamicArray__
#define __CS587__DynamicArray__


#include <stdio.h>
#include <assert.h>
#include <iostream>

template<typename T>
class DynamicArray
{

private:
    
    T * _array;             // The point of the array
    int _length;            // The length of the arary
    int _capacity;          // The capactiy of the array
    
public:
    
    /**
     * @brief Default Constructor , construct a dyanmic array with 0 length and 0 capacity
     *
     */
    
    DynamicArray();
    
    /**
     * @brief A constructor , construct a dyanmic array with specified length and value
     *
     * @param length: the length of array the user want to create
     * @param value : The default value in the array
     */
    
    DynamicArray(int length,T value);
    
    
    /**
     * @brief Copy constructor
     *
     */
    
    DynamicArray(const DynamicArray<T> & targetArray);
    
    /**
     * @brief A constructor , construct a dyanmic array with specified length
     *
     * @param length: the length of array the user want to create
     */
    
    DynamicArray(int length);
    
    /**
     * @brief Deconstructor the value at specific index .
     *
     */
    
    ~DynamicArray();
    
    
    
    /**
     * @brief Insert a value at the last of currrent dynamic array instance.
     *
     * @param The value want to be inserted.
     */
    
    void InsertAtLast(const T &value);
    
    /**
     * @brief Insert a value at the first of currrent dynamic array instance.
     *
     * @param The value want to be inserted.
     */
    
    void  InsertAtFirst(T value);
    /**
     * @brief Insert a value at a speicific index.
     *
     * @param The value want to be inserted;
     * @param The index in current dynamic array instance.
     */
    
    
    
    void InsertAtIndex(int index,T value);
    
    /**
     * @brief Remove the value at specific index .
     *
     * @param The index where your want to remove the value;
     */
    
    void RemoveAtIndex(int index);
    /**
     * @brief Remove the value.
     *
     * @param The value you want to remove .
     */
    
    void Remove(T index);
    
    /**
     * @brief preallocate the space for the current instance .
     *
     * @param The new capacity;
     */
   
    
    void Reserve(int newCapacity);
    
    /**
     * @brief Check if current instance is empty if it is . return true,otherwise return false
     *
     */
    
    bool IsEempty()const;
    
    
    /**
     * @brief Return the length of current array instance
     *
     */
    
    int GetLength()const;
    
    /**
     * @brief Return the capacity of current array instance
     *
     */
    int GetCapacity()const;
    
    /**
     * @brief delete all the element in current array instance
     *        and set the length and capacity to 0.
     */
    void Clear();
    
    /**
     * @brief Get the last object
     */
    
    T& GetLast()const;
    
    T& operator [](int index);
    
    const DynamicArray<T> & operator  =  (const DynamicArray<T>& targetArray);
    /**
     * @brief Get the frist object
     */
    
    T &GetFrist()const;
    
};



template<typename T>
DynamicArray<T>::DynamicArray()
{
//    _array=0;
//    _length=0;
//    _capacity=0;

    _array=0;
    
    _length=0;
    _capacity=0;

}

template<typename T>
DynamicArray<T>::DynamicArray(int length)
{
    _array=new T[length];
    assert(this->_array != NULL);
    
    _length=length;
    _capacity=_length;
    
}

template<typename T>
DynamicArray<T>::DynamicArray(int length,T value)
{
    _array=new T[length];
    
    assert(this->_array != NULL);
    _length=length;
    _capacity=_length;
    
    for (int i = 0; i < this->_length; i++)
    {
        _array[i]=value;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> & targetArray)
{
 
    
    if (_array!=NULL)
    {
        // delete []_array;
        //free(_array);
    }
    this->_array= new T[targetArray._capacity];
    
    this->_length = targetArray._length;
    this->_capacity = targetArray._capacity;
    
    memcpy(this->_array, targetArray._array, sizeof(T)*targetArray._length);
    
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{

    if (_array!=NULL)
    {
       delete [] _array;
        //free(_array);
       _array=NULL;
    }

  
    
   // Clear();
}

template<typename T>
void DynamicArray<T>::InsertAtLast(const T &value)
{
    
    
    if ( _length == _capacity )
    {
        Reserve((_length+1) * 2);
    }
    
  _length++;
    _array[_length-1] = value;
   
    return;
}
template<typename T>
void DynamicArray<T>::InsertAtIndex(int index,T value)
{
    
 

    
    if ( _length == _capacity )
    {
        Reserve((_length+1) * 2);
    }
    
    _length++;
    
    for(int i = _length - 1; i > index; i--)
    {
        _array[i] = _array[i-1];
    }
    
    _array[index]=value;
    return;
    
}
template<typename T>
void DynamicArray<T>::RemoveAtIndex(int index)
{
    assert(index >= 0 && index < _length);
    
    if (index == this->_length-1)
    {
        _length--;
        return;
    }
    
    for (int i=index+1; i<_length; i++)
    {
        _array[i-1]=_array[i];
    }
    
    _length--;
    return;
    
}

template<typename T>
void DynamicArray<T>::Reserve(int newCapacity)
{
    // If the new cappacity < current capacity then do nothing.
    
    if (newCapacity < this->_capacity)
    {
        return;
    }
    
    
    T * newArray = new T[newCapacity];
     memcpy(newArray, _array, sizeof(T)*_capacity);

    
    memcpy(newArray, _array, sizeof(T)*_capacity);
    if (_array != NULL)
    {
      delete [] _array;
        _array = NULL;
    }
    
    this->_capacity = newCapacity;
    this->_array = newArray;
    
    
}
template<typename T>
int DynamicArray<T>::GetLength()const
{
    return _length;
}
template<typename T>
T  &DynamicArray<T>::GetLast()const
{
    return _array[_length-1];
}
template<typename T>
T &DynamicArray<T>::GetFrist()const
{
    return _array[0];
}

template<typename T>
int DynamicArray<T>::GetCapacity()const
{
    return _capacity;
}

template<typename T>
T& DynamicArray<T>::operator [](int index)
{
    assert(index >= 0 && index <_length);
    
    return _array[index];
}

template<typename T>
const DynamicArray<T> & DynamicArray<T>::operator  =  (const DynamicArray<T>& targetArray)
{
    if(this==&targetArray)
    return *this;
    
    if (_array!=NULL)
    {
        delete[] _array;
    }
    
    _array= new T[targetArray._length];

    
    _length=targetArray._length;
    _capacity=targetArray._capacity;
    
    memcpy(this->_array, targetArray._array, sizeof(T)*targetArray._length);
    
    return *this;
}

template<typename T>
bool DynamicArray<T>::IsEempty()const
{
    if (_length == 0)
    {
        return true;
    }
    
    return false;
    
}

template<typename T>
void DynamicArray<T>::Clear()
{
    if (_array != NULL)
    {
        delete [] _array;
        _array = NULL;
    }
 
    _length=0;
    _capacity=0;
}

template<typename T>
void  DynamicArray<T>::InsertAtFirst(T value)
{
    
    InsertAtIndex(0,value);
}
template<typename T>
void  DynamicArray<T>::Remove(T value)
{
    for (int i = 0; i < _length; ++i)
    {
        if (_array[i]==value)
        {
            RemoveAtIndex(i);
        }
    }
}

#endif /* defined(__CS587__DynamicArray__) */
