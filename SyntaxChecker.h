/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include <string>
#include <fstream>
#include "GenStack.h"
#include "FileIO.h"

class SyntaxChecker
{
public:
    /**
     * variable constructor
     * @param sourceFileName - the source file to check
     */
    explicit SyntaxChecker(const std::string& sourceFileName);
    /**
     * destructor
     */
    ~SyntaxChecker();

    /**
     * perform a syntax check on the source file
     * @return - a boolean that returns true if the source file passes the syntax check, false otherwise
     */
    bool check();

private:
    GenStack<char>* delimiterStack;
    std::ifstream sourceFile;
    std::string sourceFileLine;
    int fileLineNum;
    bool ignoreChar;
    long index;

    /**
     * gets the closing delimiter based on the opening delimiter
     * @param opening - the opening delimiter
     * @return - a char representing the closing delimiter
     */
    char getClosingDelimiter(char opening);
};

#endif // SYNTAXCHECKER_H