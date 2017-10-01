#pragma once
#include <cstring>
#include <iostream>

using namespace std;
class String
{
public:
    String();
    String(int size);

    String(const char* strBuff);

    String(const String& obj);

    // Operation =
    String &operator =(const String &obj);

    ~String();

    // ************** SET *************
    void setStr(char* _str);

    // ************** GET ************
    const char *getStr();
    int getLen();
    unsigned int getSize();

    void print();
    void println();

    void input();

    //OVERLOAD  FUNCTION
    //  S1 + 'T'
    String operator +(const char symb);

    // S1 + "str"
    String operator +(const char* _str);

    // S1 + S2
    String operator +(String& myStr);

    // s1 - "str"
    String operator -(const char* _str);

    //S1 == S2
    bool operator ==(const String &_str);

    // S1 < S2
    bool operator >(const String &_str);
    // S1 > S2
    bool operator <(const String &_str);

    // S1=S2



private:
    char* str;
    unsigned int size;
};
