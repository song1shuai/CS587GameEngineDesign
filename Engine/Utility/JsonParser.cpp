//
//  JsonParser.cpp
//  CS587_ShuaiSong
//
//  Created by shuai song on 2/7/14.
//  Copyright (c) 2014 shuai song. All rights reserved.
//

#include "JsonParser.h"
JValue *JsonParser::ParseObject(TOKENARRAY&tokenArray,int &i, JValue *root)
{
    i++;
    root->_type=JOBJECT;
    
    while (tokenArray[i].type!=BRACKET_CLOSE)
    {
        
        int rootIndex=i;
        JValue *child =new JValue();
        Parse(tokenArray, ++i,child);
        root->AddToObject(tokenArray[rootIndex].value, child);
        
  
    }
   
    return root;
    
}
JValue *JsonParser::ParseArray(TOKENARRAY&tokenArray,int &i, JValue *root)
{
    root->_type = JARRAY;
    i++;
    while (tokenArray[i].type!=ARRAY_CLOSE)
    {
        JValue *child =new JValue();
        Parse(tokenArray, i,child);
        root->AddToArray(child);
    
        
    }
   
    return root;
}

JValue *JsonParser::Parse(TOKENARRAY &tokenArray,int &i,JValue * root)
{

    switch (tokenArray[i].type)
    {
        case BRACKET_OPEN:
        ParseObject(tokenArray, i,root);
        break;
        
        case ARRAY_OPEN:
        root=ParseArray(tokenArray, i,root);
        break;
        
        case STRING:
        root->_type =JSTRING;
        root->_stringValue=tokenArray[i].value;
            
        break;
        
        case NUMBER:
        root->_type =JNUMBER;
        root->_stringValue=tokenArray[i].value;
        break;
        
        case BOOLEAN:
        root->_type =JBOOLEAN;
        root->_stringValue=tokenArray[i].value;
        //i++;
        break;
        
        case NUL:
        root->_type =JNULL;
        root->_stringValue="null";
        break;
        
        default:
        break;
    }
    i++;
    return root;

}

JValue *JsonParser::ParseFile(const std::string& filePath)
{
    std::ifstream in(filePath.c_str());
    
    if (!in.is_open())
    {
        std::cout << "Error opening file"<<" "<< filePath<<std::endl;
        
    }
    
    std::string buffer;
    std::string tmp;
    
    while (!in.eof())
    {
        
        getline(in, tmp);
        buffer+=tmp;
    };
    
    in.close();
    int i=0;
    TOKENARRAY tokenArray=GetToken(buffer);
    JValue  *root=new JValue();
    
    
    Parse(tokenArray,i,root);
    return root;
}

TOKENARRAY JsonParser::GetToken(std::string jsonFile)
{
    TOKENARRAY tokenArray;
    int index=0;
    while (jsonFile[index]!='\0')
    {
//    for(int index=0;index<jsonFile.length();index++)
//    {
    
        if (jsonFile[index]=='{')
        {
            tokenArray.InsertAtLast(Token("{",BRACKET_OPEN));
            index++;
            continue;
        }
        if (jsonFile[index]=='"')
        {
            int stringStartIndex=index+1;
            int nextCommaIndex=jsonFile.find('"',index+1);
            std::string subString=jsonFile.substr(index+1,nextCommaIndex-stringStartIndex);
            tokenArray.InsertAtLast(Token(subString,STRING));
            index=nextCommaIndex+1;
            continue;
        }
        if (jsonFile[index]=='}')
        {
            tokenArray.InsertAtLast(Token("}",BRACKET_CLOSE));
            index++;
            continue;
        }
        if (jsonFile[index]=='[')
        {
            tokenArray.InsertAtLast(Token("[",ARRAY_OPEN));
            index++;
            continue;
        }
        if (jsonFile[index]==']')
        {
            tokenArray.InsertAtLast(Token("]",ARRAY_CLOSE));
            index++;
            continue;
        }
        if (jsonFile[index]=='t')
        {
            std::string TrueString=jsonFile.substr(index,4);
            tokenArray.InsertAtLast(Token(TrueString,BOOLEAN));
            index=index+4;
            continue;
        }
        if (jsonFile[index]=='f')
        {
            std::string falseString=jsonFile.substr(index,5);
            tokenArray.InsertAtLast(Token(falseString,BOOLEAN));
            index=index+5;
            continue;
        }
 
        if ((jsonFile[index]>='0'&&jsonFile[index]<='9')||jsonFile[index]=='-')
        {
            int numStartIndex=index;
            index++;
            while ((jsonFile[index]>='0'&&jsonFile[index]<='9')||jsonFile[index]=='.')
            {
               index++;
            }
            int numEndIndex=index;
            std:: string numString=jsonFile.substr(numStartIndex,numEndIndex-numStartIndex);
            tokenArray.InsertAtLast(Token(numString,NUMBER));
            //index=numEndIndex+1;
            continue;
            
        }
        
        
        else
        {
            index++;
        }
        
    }
    
//   for(int i =0;i<tokenArray.GetLength();i++)
//    {
//       std::cout<< tokenArray[i].value<<std::endl;
//    }
    
    
    return  tokenArray;
}

