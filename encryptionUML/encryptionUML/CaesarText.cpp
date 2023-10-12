#include "CaesarText.h"
#define KEY 3


/*
summary: a build function + it will encrypt the text
return: nothing
input: std::string text
*/
CaesarText::CaesarText(std::string text)
{
	_text = CaesarText::encrypt(text);
}

/*
summary: it will destroy the build function (it will clear the text)
return: nothing
input: nothing
*/
CaesarText::~CaesarText()
{
	_text.clear();
}

/*
summary: it will encrypt a text with the key (3) and return it 
return: std::string text
input: std::string text
*/
std::string CaesarText::encrypt(std::string text)
{
	return ShiftText::encrypt(text, KEY);
}

/*
summary: it will decrypt a text with the key (3) and return it
return: std::string text
input: std::string text
*/
std::string CaesarText::decrypt(std::string text)
{
	return ShiftText::decrypt(text, KEY);
}

/*
summary: it will encrypt the text with the key + it will make isEncrypted to true and it will return _text
return: _text
input: none
*/
std::string CaesarText::encrypt()
{
	_text = ShiftText::encrypt(_text, KEY);
	_isEncrypted = true;
	return _text;
}

/*
summary: it will decrypt the text with the key + it will make is isEncrypted to true and it will return _text
return: nothing
input: std::string text
*/
std::string CaesarText::decrypt()
{
	_text = ShiftText::decrypt(_text, KEY);
	_isEncrypted = false;
	return _text;
}

/*
summary: it will use the operator and it will return s.encrypt
return: nothing
input: const std::ostream& os, caesarText& s
*/
std::ostream& operator<<(const std::ostream& os, CaesarText& s)
{
	return std::cout << s.encrypt();
}
