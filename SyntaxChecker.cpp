/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#include <iostream>
#include <string>
#include <fstream>
#include "SyntaxChecker.h"
#include "GenStack.h"
#include "FileIOException.h"

// variable constructor
SyntaxChecker::SyntaxChecker(const std::string& sourceFileName)
: delimiterStack(new GenStack<char>(10)), fileLineNum(0), ignoreChar(false), index(0)
{
    sourceFile.open(sourceFileName);
    sourceFile.clear();
    sourceFile.seekg(0, std::ios::beg);
}

// destructor
SyntaxChecker::~SyntaxChecker()
{
    delete delimiterStack;
    sourceFile.close();
}

// perform a syntax check on the source file
bool SyntaxChecker::check()
{
    try
    {
        if (sourceFile) // if the source file is good
        {
            bool inDoubleQuotes = false;
            bool inSingleQuotes = false;

            while (getline(sourceFile, sourceFileLine)) // read each line of the source file
            {
                ++fileLineNum; // increment line number
                index = sourceFileLine.find("//"); // find position of comment on line, if any
                index = ((index != std::string::npos) ? index : sourceFileLine.size());

                for (int i = 0; i < index; ++i) // check only the characters before the comment index
                {
                    if (!ignoreChar) // if we are not ignoring characters in a string
                    {
                        switch (sourceFileLine[i])
                        {
                            case '"': // if we find the '"' that opens the string
                                ignoreChar = true; // start ignoring it
                                inDoubleQuotes = true;
                                break;
                            case '\'': // if we find the ''' that opens the string
                                ignoreChar = true; // start ignoring it
                                inSingleQuotes = true;
                                break;
                            case '(':
                            case '{':
                            case '[':
                                delimiterStack->push(sourceFileLine[i]); // push opening delimiter to stack
                                break;
                            case ')':
                                if (!(delimiterStack->isEmpty())) // if the delimiter stack is not empty
                                {
                                    if (delimiterStack->peek() !=
                                        '(') // if the closing delimiter doesn't match up with the closing delimiter
                                    {
                                        std::cout << "Line " << fileLineNum << " expected "
                                                  << getClosingDelimiter(delimiterStack->pop())
                                                  << " and found )." << std::endl;
                                        delete delimiterStack;
                                        delimiterStack = new GenStack<char>(10);
                                        return false;
                                    }
                                    delimiterStack->pop();
                                } else
                                {
                                    std::cout << "Line " << fileLineNum << " dangling )" << std::endl;
                                    return false;
                                }
                                break;
                            case '}':
                                if (!(delimiterStack->isEmpty())) // if the delimiter stack is not empty
                                {
                                    if (delimiterStack->peek() !=
                                        '{') // if the closing delimiter doesn't match up with the closing delimiter
                                    {
                                        std::cout << "Line " << fileLineNum << " expected "
                                                  << getClosingDelimiter(delimiterStack->pop())
                                                  << " and found }." << std::endl;
                                        delete delimiterStack;
                                        delimiterStack = new GenStack<char>(10);
                                        return false;
                                    }
                                    delimiterStack->pop();
                                } else
                                {
                                    std::cout << "Line " << fileLineNum << " dangling }" << std::endl;
                                    return false;
                                }
                                break;
                            case ']':
                                if (!(delimiterStack->isEmpty())) // if the delimiter stack is not empty
                                {
                                    if (delimiterStack->peek() !=
                                        '[') // if the closing delimiter doesn't match up with the closing delimiter
                                    {
                                        std::cout << "Line " << fileLineNum << " expected "
                                                  << getClosingDelimiter(delimiterStack->pop())
                                                  << " and found ]." << std::endl;
                                        delete delimiterStack;
                                        delimiterStack = new GenStack<char>(10);
                                        return false;
                                    }
                                    delimiterStack->pop();
                                } else
                                {
                                    std::cout << "Line " << fileLineNum << " dangling ]" << std::endl;
                                    return false;
                                }
                                break;
                            default:
                                break;
                        }
                    } else
                    {
                        switch (sourceFileLine[i])
                        {
                            case '"': // if we find the '"' that closes the string
                                if (inDoubleQuotes) // making sure its in double quotes
                                {
                                    ignoreChar = false; // stop ignoring it
                                    inDoubleQuotes = false;
                                }
                                break;
                            case '\'': // if we find the ''' that opens the
                                if (inSingleQuotes) // making sure its in single quotes
                                {
                                    ignoreChar = false; // stop ignoring it
                                    inSingleQuotes = false;
                                }
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
        else
        {
            throw FileIOException("Operation on invalid file");
        }
    }
    catch (FileIOException& err)
    {
        std::cout << err.getErr() << std::endl;
        return false;
    }

    if (!(delimiterStack->isEmpty())) // if the delimiter stack isn't empty, then no closing delimiters are at the end of the file
    {
        std::cout << "Reached end of file. There is no closing delimiter for " << delimiterStack->peek() << std::endl;
        return false;
    }
    return true;
}

// gets the closing delimiter based on the opening delimiter
char SyntaxChecker::getClosingDelimiter(char opening)
{
    switch (opening)
    {
        case '(':
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
        default:
            return ' ';
    }
}