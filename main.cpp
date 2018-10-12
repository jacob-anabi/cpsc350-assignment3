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
            if (syntaxChecker->check()) // check syntax of the source file
            {
                while (true)
                {
                    std::cout << "Source file has proper syntax. Would you like to process another one? (Y/n) ";
                    std::getline(std::cin, input);

                    if (input == "Y") // if they want to enter another file
                    {
                        keepGoing = true;
                        std::cout << "What is the source file: ";
                        std::getline(std::cin, sourceFileName);
                        delete syntaxChecker; // delete the old syntax checker
                        syntaxChecker = new SyntaxChecker(sourceFileName); // create new SyntaxChecker object for the new file
                        break;
                    }
                    else if (input == "n") // if they dont want to enter another file
                    {
                        keepGoing = false;
                        break;
                    }
                    else // if they enter an invalid response
                    {
                        std::cout << "Invalid input. Try again. " << std::endl;
                    }
                }
            }
            else
            {
                keepGoing = false; // if the source file has improper syntax, exit the program
            }
        } while (keepGoing);

        delete syntaxChecker;
    }
    return 0;
}