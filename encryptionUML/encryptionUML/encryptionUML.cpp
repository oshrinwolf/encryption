#include <iostream>
#include "PlainText.h"
#include "ShiftText.h"
#include "SubstitutionText.h"
#include "FileHelper.h"
#include "CaesarText.h"
#include <sstream>

void choose_Functions();
void encryption_String();
void encryption_File();

void shiftText_Function(std::string text, int choice, int key);
void caesarText_Function(std::string text, int choice);


/*
* summary: it will print the menu and then it will run the choose_Functions
* input: void
* return: none
*/
int main(void)
{
	std::cout << "\n1 : Encryption and decryption a string." << std::endl;
	std::cout << "2 : Encrpytion and decryption a file." << std::endl << std::endl;

	choose_Functions();
}


/*
* summary: it will print the menu depends on the choice and you can choose
* input: none
* return: none
*/
void choose_Functions()
{
	std::cout << "Choice: " << std::endl;
	int choice = 0;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		encryption_String();
		break;
	case 2:
		encryption_File();
		break;
	default:
		std::cout << "[ERROR] Please try again! [ERROR]" << std::endl << std::endl;
		choose_Functions();
	}
}


/*
* summary: it will print the menu depends on the choice and you can choose
* input: none
* return: none
*/
void caesarText_Function(std::string text, int choice)
{
	if (choice == 1)
	{
		std::cout << "Enter a string: ";
		std::cin >> text;
		std::cout << CaesarText::encrypt(text);
		std::cout << std::endl;
		main();
	}
	else if (choice == 2)
	{
		std::cout << "Enter a string: ";
		std::cin >> text;
		std::cout << CaesarText::decrypt(text);
		std::cout << std::endl;
		main();
	}
}

/*
* summary: shiftText_Function - you enter a string and a key it will print you the encrypt or the decrypt, depends on you
* input: std::string text, int choice, int key
* return: none
*/
void shiftText_Function(std::string text, int choice, int key)
{
	if (choice == 1)
	{
		std::cout << "Enter a string: ";
		std::cin >> text;
		std::cout << "Enter a key: ";
		std::cin >> key;
		std::cout << ShiftText::encrypt(text, key);
		main();
	}
	else if (choice == 2)
	{
		std::cout << "Enter a string: ";
		std::cin >> text;
		std::cout << "Enter a key: ";
		std::cin >> key;
		std::cout << ShiftText::decrypt(text, key);
		main();
	}
}

/*
* summary: this is the menu and you can choose your command
* input: none
* return: none
*/
void encryption_String()
{
	std::string text;
	int choice = 0;
	int key = 0;
	int choose = 0;

	std::cout << std::endl;
	std::cout << "1 : CaesarText\n";
	std::cout << "2 : ShiftText\n";
	std::cout << "3 : SubstitutionText\n";
	std::cout << "Choice: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
	case 1:

		std::cout << "\n1 : Encryption" << std::endl;
		std::cout << "2 : Decryption" << std::endl;
		std::cout << "Choice: ";
		std::cin >> choose;
		std::cout << std::endl;
		
		if (choose == 1)
		{
			caesarText_Function(text, choose);
		}
		else if (choose == 2)
		{	
			caesarText_Function(text, choose);
		}
		break;
	case 2:
		std::cout << "\n1 : Encryption" << std::endl;
		std::cout << "2 : Decryption" << std::endl;
		std::cout << "Choice: ";
		std::cin >> choose;
		std::cout << std::endl;

		if (choose == 1)
		{
			shiftText_Function(text, choose, key);
		}
		else if (choose == 2)
		{
			shiftText_Function(text, choose, key);
		}
		break;
	case 3:

	default: 
		std::cout << "[ERROR] Please try again! [ERROR]" << std::endl << std::endl;
		encryption_String();
		break;
	}
}

void encryption_File()
{

}