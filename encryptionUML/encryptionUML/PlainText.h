#pragma once
#include <string>


class PlainText
{
protected:
	//fields
	std::string _text;
	bool _isEncrypted;

public:
	//fields
	static int count;
	//methods
	PlainText(std::string text = "");
	~PlainText();
	bool isEncrypted() const;
	std::string getText() const;
	friend std::ostream& operator<<(const std::ostream& os, PlainText& s);

};