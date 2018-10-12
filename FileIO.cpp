/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#include <string>
#include <fstream>
#include <iostream>
#include "FileIO.h"
#include "FileIOException.h"

// variable constructor
FileIO::FileIO(const std::string& fileName, char operMode)
: fileName(fileName), operMode(operMode)
{
    if (operMode == 'r')
    {
        inFile.open(fileName, std::ios::in); // if in read mode, create a read file object
    }
}

// copy constructor
FileIO::FileIO(const FileIO& fileIO)
: fileName(fileIO.fileName), operMode(fileIO.operMode)
{
    if (fileIO.operMode == 'r')
    {
        inFile.open(fileIO.fileName, std::ios::in); // if in read mode, create a read file object
    }
}

// destructor
FileIO::~FileIO()
{
    if (inFile.is_open())
    {
        inFile.clear();
        inFile.seekg(0, std::ios::beg);
        inFile.close(); // close the read file if it is open
    }
}

// changes the file you want to process
void FileIO::changeFile(const std::string& newFileName, char newOperMode)
{
    if (inFile.is_open())
    {
        inFile.close(); // close the previous read file if it is open
    }

    fileName = newFileName;
    operMode = newOperMode;

    if (operMode == 'r')
    {
        inFile.open(fileName, std::ios::in); // if in read mode, create a read file object
    }
}

// reads the file line by line
bool FileIO::readFileLine(std::string& line)
{
    if (operMode != 'r') // if they are in the wrong operating mode
    {
        throw FileIOException("Operation on file in wrong operating mode");
    }

    if (inFile) // if the inFile is valid
    {
        if (getline(inFile, line)) // if we are not at the end of the file
        {
            return true;
        }
        else // return to beginning line
        {
            inFile.clear();
            inFile.seekg(0, std::ios::beg);
        }
    }
    else
    {
        throw FileIOException("Operation on invalid file");
    }
    return false;
}

// writes a line to a file
void FileIO::writeFileLine(const std::string& line, char writeMode)
{
    if (operMode != 'w')
    {
        throw FileIOException("Writing in invalid operation mode");
    }
    std::ofstream outFile;

    switch (writeMode)
    {
        case 'o': // overwrite mode
            outFile.open(fileName, std::ios::out);
            break;
        case 'a': // append mode
            outFile.open(fileName, std::ios::out | std::ios::app);
            break;
        case 'd': // delete mode
            outFile.open(fileName, std::ios::out | std::ios::trunc);
            break;
        default:
            throw FileIOException("File written in invalid write mode");
    }

    if (outFile) // if the outFile is valid
    {
        outFile << line << std::endl;
        outFile.close();
    }
    else
    {
        outFile.close();
        throw FileIOException("Operation on invalid file");
    }
}
