//
//  JValue.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/7/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef CS587_ShuaiSong_JValue_h
#define CS587_ShuaiSong_JValue_h
#include "DynamicArray.h"
#include "HashMap.h"
#include <sstream>
class JValue;
struct KeyValue;
enum JType
{
    JSTRING,
    JNUMBER,
    JBOOLEAN,
    JARRAY,
    JNULL,
    JOBJECT
};

struct KeyValue
{
    std::string  key;
    JValue *value;
    
};


typedef   DynamicArray<KeyValue> JOBJECTARRAY;
typedef   DynamicArray<JValue*> JVALUEARRAY;
class JValue
{
private:
    
    friend class JsonParser;
    
    JType _type;
    std::string _stringValue;
    
    JOBJECTARRAY _objectArray;
    JVALUEARRAY  _jvalueArray;
    
    HashMap<int> _indexMap;
    
    void AddToObject( std::string key,JValue *value);
    void AddToArray(JValue *value);
    
public:
    
    JValue(const JValue & copy);
    JValue();
    std::string ToString();
    int    ToInt();
    float  ToFloat();
    bool   ToBool();
    void * ToNull();
    int GetLength();
    JValue &operator=(const JValue & copy);
    JValue &operator[](std::string s);
    JValue &operator[](int i);
};



#endif
