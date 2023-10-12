#include "PlainText.h"
#include <iostream>

int PlainText::count = 0;

/*
* summary: this is the build function
input: std::string text
return: nothing
*/
PlainText::PlainText(std::string text)
{
	PlainText::count = PlainText::count + 1;
	this->_text = text;
	this->_isEncrypted = false;

}

/*
* summary: it will delete plaintext
input: nothing
return: nothing
*/
PlainText::~PlainText()
{
	this->_text.clear();
	this->_isEncrypted = false;
}

/*
* summary: this will return if it's encrypted
input: nothing
return: this-<_isEncrypted
*/
bool PlainText::isEncrypted() const
{
	return this->_isEncrypted;
}

/*
* summary: this will return text
input: nothing
return: this->_text
*/
std::string PlainText::getText() const
{
	return this->_text;
}

/*
* summary: it will return text when using the operator
input: const std::ostream& os, PlainText& s
return: std::cout << s._text
*/
std::ostream& operator<<(const std::ostream& os, PlainText& s)
{
	return std::cout << s._text;
}
