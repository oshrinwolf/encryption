#include "SubstitutionText.h"
#include <fstream>
#include <iostream>
#include <string>

/*
summary: it will encrypt the file and isEncrypted = true
return: std::string text, std::string dictornaryFileName
input: none
*/
SubstitutionText::SubstitutionText(std::string text, std::string dictionaryFileName)
{
	this->_dictionaryFileName = dictionaryFileName;
	this->_text = SubstitutionText::encrypt(text, dictionaryFileName);
	this->_isEncrypted = true;
}

/*
summary: it will destroy this function, meaning text = null
return: none
input: none
*/
SubstitutionText::~SubstitutionText()
{
	this->_text.clear();

}

/*
summary: it will encrypt the dictionaryFile
return: std::string text, std::string dictornaryFileName
input: text
*/
std::string SubstitutionText::encrypt(std::string text, std::string dictionaryFileName)
{
	dictionaryFileName = "C:\\Users\\erikg\\OneDrive\\Desktop\\" + dictionaryFileName;

	std::ifstream file;
	file.open(dictionaryFileName);
	std::string normal_words;
	std::string encryped_words;
	if (file.good())
	{
		for (std::string line; getline(file, line);)
		{
			normal_words += line[0];
			encryped_words += line[2];
		}

	}

	for (int i = 0; i < text.length(); i++)
	{
		for (int j = 0; j < normal_words.length(); j++)
		{
			if (text[i] == normal_words[j])
			{
				text[i] = encryped_words[j];
				break;
			}
		}
	}

	file.close();
	return text;
}

/*
summary: it will decrypt the dictionaryFile
return: std::string text, std::string dictornaryFileName
input: text
*/
std::string SubstitutionText::decrypt(std::string text, std::string dictionaryFileName)
{
	dictionaryFileName = "C:\\Users\\erikg\\OneDrive\\Desktop\\" + dictionaryFileName;
	std::ifstream file;
	file.open(dictionaryFileName);


	std::string normal_words;
	std::string encryped_words;
	if (file.good())
	{
		for (std::string line; getline(file, line);)
		{
			normal_words += line[0];
			encryped_words += line[2];
		}

	}

	for (int i = 0; i < text.length(); i++)
	{
		for (int j = 0; j < normal_words.length(); j++)
		{
			if (text[i] == encryped_words[j])
			{
				text[i] = normal_words[j];
				break;
			}
		}
	}
	file.close();
	return text;
}

/*
summary: if isencrypted is false then it will encrypt the dictionaryFile and make the encrypted true
return: none
input: text
*/
std::string SubstitutionText::encrypt()
{
	if (_isEncrypted == false)
	{
		_isEncrypted = true;
		this->_text = SubstitutionText::encrypt(this->_text, this->_dictionaryFileName);
		return this->_text;
		
	}
	return this->_text;
}

/*
summary: if isencrypted is true then it will decrypt the dictionaryFile and make the encrypted false
return: none
input: text
*/
std::string SubstitutionText::decrypt()
{
	if (_isEncrypted == true)
	{
		_isEncrypted = false;
		this->_text = SubstitutionText::decrypt(this->_text, this->_dictionaryFileName);
		return this->_text;
	}
	return this->_text;
}

/*
summary: when using the operator << it will return s.encrypted
return: std::cout << s.encrypted()
input: const std::ostream& os, SubstitutionText& s
*/
std::ostream& operator<<(const std::ostream& os, SubstitutionText& s)
{
	return std::cout << s.encrypt();
}
