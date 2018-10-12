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
#include "SyntaxChecker.h"


int main(int argc, char** argv)
{
    if (argc > 1)
    {
        SyntaxChecker* syntaxChecker = new SyntaxChecker(argv[1]);
        bool keepGoing;
        std::string input;
        std::string sourceFileName;

        do
        {
            if (syntaxChecker->check())
            {
                while (true)
                {
                    std::cout << "Source file has proper syntax. Would you like to process another one? (Y/n) ";
                    std::getline(std::cin, input);

                    if (input == "Y")
                    {
                        keepGoing = true;
                        std::cout << "What is the source file: ";
                        std::getline(std::cin, sourceFileName);
                        delete syntaxChecker;
                        syntaxChecker = new SyntaxChecker(sourceFileName);
                        break;
                    }
                    else if (input == "n")
                    {
                        keepGoing = false;
                        break;
                    }
                    else
                    {
                        std::cout << "Invalid input. Try again. " << std::endl;
                    }
                }
            }
            else
            {
                keepGoing = false;
            }
        } while (keepGoing);

        delete syntaxChecker;
    }
    return 0;
}