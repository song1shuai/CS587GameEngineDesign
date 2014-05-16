//
//  JValue.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/13/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//
#include "JValue.h"
JValue::JValue()
{

};
void JValue::AddToObject( std::string key,JValue *value)
{
    KeyValue tmp;
    tmp.key=key;
    tmp.value=value;
    
    _indexMap.Insert(key,_objectArray.GetLength());
    _objectArray.InsertAtLast(tmp);
    
    
}
JValue::JValue(const JValue & copy)
{
    _type = copy._type;
    _stringValue = copy._stringValue;
    _objectArray = copy._objectArray;
    _indexMap = copy._indexMap;
    
}
JValue &JValue::operator=(const JValue & copy)
{
    return *this;
};
void JValue::AddToArray(JValue *value)
{
    _jvalueArray.InsertAtLast(value);
}
std::string JValue::ToString()
{
    return _stringValue;
}
int JValue::ToInt()
{
    std::stringstream sstream;
    sstream << _stringValue;
    int i;
    sstream >> i;
    return i;
    
}
float  JValue::ToFloat()
{
    std::stringstream sstream;
    sstream << _stringValue;
    float i;
    sstream >> i;
    return i;
}
bool   JValue::ToBool()
{
    if (_stringValue=="true")
    {
        return true;
    }
    return  false;
}
void * JValue::ToNull()
{
    return NULL;
}
int JValue::GetLength()
{
    if (_type==JARRAY)
    {
        return _jvalueArray.GetLength();
    }
    if (_type==JOBJECT)
    {

        return _objectArray.GetLength();
    }
    return 0;
}

JValue &JValue::operator[](std::string s)
{
    int index;
    
    
     //_indexMap.GetAllKey();
    
    int *prt = _indexMap.Find(s);
   // std::cout<<s<<std::endl;
    assert(prt!=NULL);
    index= *prt;
    
    return *_objectArray[index].value;
}
JValue &JValue::operator[](int i)
{
    if (_type==JARRAY)
    {
        return *_jvalueArray[i];
    }
    if (_type==JOBJECT)
    {
        return *_objectArray[i].value;
    }
    return *this;
    
}