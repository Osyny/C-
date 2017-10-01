#include "str.h"


String::String()
{
    size = 80;
    str = new char[size];
    str[0] = '\0';
}

String::String(int size)
{
    if(size > 0)
        this->size = size;
    else
        this->size = 80;

    str = new char[this->size];
    str[0] = '\0';

}

String::String(const char *strBuff)
{
    size = strlen(strBuff) + 1;
    str = new char[size];
    strcpy(str, strBuff);
}

String::String(const String &obj)
{
    str = _strdup(obj.str);
    size = obj.size;
}

String &String::operator =(const String &obj)
{
    if (this == &obj)
        return *this;

    delete[] str;
    str = _strdup(obj.str);
    size = obj.size;

    return *this;
}

String::~String()
{
    delete[] str;
}

void String::setStr(char *_str)
{
    delete[] str;
    str = _strdup(_str);
    size = strlen(str) + 1;
}

const char *String::getStr()
{
    return str;
}

int String::getLen()
{
    return strlen(str);
}

unsigned int String::getSize()
{
    return size;
}

void String::print()
{
    cout << str;
}

void String::println()
{
    cout << str << endl;
}

void String::input()
{
    char buff[250] = { 0 };
    cout << "\n Enter string : ";
    cin.getline(buff, 250);

    if (strlen(buff) > getLen())
    {
        delete[] str;
        str = _strdup(buff);
        size = getLen() + 1;
    }
    else
    {
        strcpy(str, buff);
    }
}
//  S1 + 'T'
String String::operator +(const char symb)
{
    char* tmp = new char[getLen() + 2];
    strcpy(tmp, str);
    tmp[getLen()] = symb;
    tmp[getLen() + 1] = '\0';

    String result(tmp);
    delete[] tmp;
    return result;
}
// S1 + S2
String String::operator +(String &myStr)
{
    char* tmp = new char[getLen() + myStr.getLen() + 2];
    strcpy(tmp, str);
    strcat(tmp, myStr.getStr());

    String result(tmp);
    delete[] tmp;
    return result;
}

// S1 + "str"
String String::operator +(const char *_str)
{
    char* tmp = new char[getLen() + strlen(_str) + 2];
    strcpy(tmp, str);
    strcat(tmp, _str);

    String result(tmp);
    delete[] tmp;
    return result;
}

// s1 - "str"
String String::operator -(const char* _str)
{
   int index = strstr(str, _str) - str;

   if (index >= 0)
   {
       int _len = strlen(_str);
       char* tmp = new char[getLen() + 1];
       strcpy(tmp, str);
       strcpy(tmp + index, str + index + _len);

       String result(tmp);
       delete[] tmp;
       return result -_str;
   }
   return *this;
}


bool String::operator ==(const String &_str)
{
    return (strcmp(str, _str.str) == 0) ? true : false;
}

bool String::operator >(const String &_str)
{
    return strcmp(str, _str.str) > 0;
}

bool String::operator <(const String &_str)
{
    return strcmp(str, _str.str) < 0;
}
