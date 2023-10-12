#include "ShiftText.h"

/*
summary: it will build a function and encrypt the text using the key
return: none
input: std::string text, int key
*/
ShiftText::ShiftText(std::string text, int key)
{
    _text = ShiftText::encrypt(text, key);
    this->_isEncrypted = true;
	this->_key = key;
}

/*
summary: it delete the shiftext
return: none
input: none
*/
ShiftText::~ShiftText()
{
    _text.clear();
	this->_key = 0;
}

/*
summary: it will encrypt the text using the key
return: text
input: std::string text, int key
*/
std::string ShiftText::encrypt(std::string text, int key)
{
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            text[i] = ch;
        }
         else if (ch >= 'A' && ch <= 'Z') {
         ch = ch + key;
         if (ch > 'Z') {
             ch = ch - 'Z' + 'A' - 1;
         }
         text[i] = ch;
         }
    }
    return text;
}

/*
summary: it will decrypt the text using the key
return: text
input: std::string text, int key
*/
std::string ShiftText::decrypt(std::string text, int key)
{
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            text[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            text[i] = ch;
        }
    }
    return text;
}



/*
summary: it will encrypt the text if it's not encrypted
return: text
input: none
*/
std::string ShiftText::encrypt()
{
    if (this->_isEncrypted == true)
    {
        return this->_text;
    }
    this->_isEncrypted = true;
    this->_text = ShiftText::encrypt(this->_text, this->_key);
    return this->_text;
}

/*
summary: it will decrypt the text if it's encrypted
return: text
input: none
*/
std::string ShiftText::decrypt()
{
    if (this->_isEncrypted == false)
    {
        return this->_text;
    }
    this->_isEncrypted = false;
    this->_text =  ShiftText::decrypt(this->_text, this->_key);
    return this->_text;
}

std::ostream& operator<<(const std::ostream& os, ShiftText& s)
{
    std::cout << "ShiftText" << std::endl;
    std::string encrypted = s.encrypt();
    s._text = encrypted;
    std::string stringName = s._text;
    s._isEncrypted = true;
    return std::cout << stringName;
}
