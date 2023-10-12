#include "FileHelper.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


/*
summary: it will put to text all the info of the file
return: text
input: std::string fileName
*/
std::string FileHelper::readFileToString(std::string fileName)
{
    std::ifstream f(fileName);
    std::string text;

    if (f.is_open()) {
        char mychar;
        while (f) {
            mychar = f.get();
            text += mychar;
        }
    }
    f.close();
    return text;
}

/*
summary: it will copy the inpunFile to outputFile
return: nothing
input: std::string inputFileName, std::string outputFileName
*/
void FileHelper::writeWordsToFile(std::string inputFileName, std::string outputFileName)
{
    std::fstream input;
    std::ofstream output;
    std::string chars;

    input.open(inputFileName);
    output.open(outputFileName);

    if (input.good() && output.good())
    {
        while (input >> chars)
        {
            output << chars << "\n";
        }
    }



}

/*
summary: it will copy the text and put it to the outputFile
return: nothing
input: std::string text, std::string outputFileName
*/
void FileHelper::saveTextInFile(std::string text, std::string outputFileName)
{
    std::string line;
    std::ofstream output;

    output.open(outputFileName);

    
        if (output.is_open())
        {
            for (int i = 0; i < text.length(); i++) {
                output << text[i];
            }
            output.close();
        }
}