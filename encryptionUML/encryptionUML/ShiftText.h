#pragma once
#include "PlainText.h"
#include <string>
#include <iostream>


class ShiftText : public PlainText
{
private:
	//fields
	int _key;

public:
	//methods
	
	ShiftText(std::string text = "", int key = 10);
	~ShiftText();
	static std::string encrypt(std::string text, int key);
	static std::string decrypt(std::string text, int key);
	std::string encrypt();
	std::string decrypt();
	friend std::ostream& operator<<(const std::ostream& os, ShiftText& s);

};