//
//  StateMachine.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/6/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__StateMachine__
#define __CS587_ShuaiSong__StateMachine__

#include <iostream>
#include "DynamicArray.h"
#include "IState.h"
#include "HashMap.h"
#include <string>
#include "IStateController.h"
template <typename T>
class StateMachine:public IStateController
{
protected:
    
    DynamicArray<IState<T>*>    _globelState;              //The globel state list
    IState<T>*                  _currentState;             //The current state
    HashMap<IState<T>*>         _stateMap;                 //The statemap use for get the state
    T *                         _owenr;                    //The owener of this stateMachine
    
public:
    
    StateMachine(T * owenr):_owenr(owenr),_currentState(NULL){};
    virtual ~StateMachine()
    {
    };
    void AddToGlobel(std::string name);                     // Add the state to the globe by given name
    void ChangeToState(std::string name);                   // quit the current state and entered int to a new state
    void Update();                                          // Update the current state and globel state
    void AddState(std::string name , IState<T> * newState); // add a new state to state map
    
};
template <typename T>
void StateMachine<T>::ChangeToState(std::string name)
{
    /*
     find this state in the state map if it existed , exit the current state 
     enter into new state.
     */
    
    
    IState<T> *newState = *_stateMap.Find(name);
    
    assert(newState);
    
    if (_currentState==newState)
    {
        return;
    }
    
    if (_currentState)
    {
        _currentState->Exit(_owenr);
    }
    
    _currentState =newState;
    _currentState->Enter(_owenr);
    
}

template <typename T>
void StateMachine<T>::Update()
{
    
    for (int i=0; i<_globelState.GetLength(); ++i)
    {
        _globelState[i]->Execute(_owenr,this);
    }
    
    _currentState->Execute(_owenr,this);
    
}
template <typename T>
void StateMachine<T>::AddToGlobel(std::string name)
{
    
    IState<T> *newState = *_stateMap.Find(name);
    assert(newState);
    newState->Enter(_owenr);
    _globelState.InsertAtLast(newState);
    
}
template <typename T>
void  StateMachine<T>::AddState(std::string name , IState<T> * newState)
{
    
    _stateMap.Insert(name,newState);
}

#endif /* defined(__CS587_ShuaiSong__StateMachine__) */
