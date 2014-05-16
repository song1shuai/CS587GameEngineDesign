//
//  JsonParser.h
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/7/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#ifndef __CS587_ShuaiSong__JsonParser__
#define __CS587_ShuaiSong__JsonParser__

#include <iostream>
#include "JValue.h"
#include <string>
#include "DynamicArray.h"
#include <fstream>  
enum TokenType
{
    UNKNOWN,
    STRING,
    NUMBER,
    ARRAY_OPEN,
    ARRAY_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE,
    BOOLEAN,
    NUL
};

struct Token
{
    std::string value;
    TokenType type;
    Token(std::string value=" ",TokenType type=UNKNOWN):value(value),type(type){}
    Token(const Token &token)
    {
        value=token.value;
        type=token.type;
    }
    const Token & operator  =  (const Token& token)
    {
        this->value=token.value;
        this->type=token.type;
         return *this;
    }
};

typedef DynamicArray<Token>  TOKENARRAY;

class JsonParser
{
  
   friend class JValue;
    
private:
   
    static  TOKENARRAY GetToken(std::string jsonFile);
    static JValue *Parse(TOKENARRAY& ,int &i,JValue * root);
    static JValue *ParseObject(TOKENARRAY&,int &i, JValue *root);
    static   JValue *ParseArray(TOKENARRAY&,int &i, JValue *root);
    
public:
    static  JValue * ParseFile(const std::string& filePath);
    
};


#endif /* defined(__CS587_ShuaiSong__JsonParser__) */
