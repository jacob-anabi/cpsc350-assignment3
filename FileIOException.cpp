/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#include "FileIOException.h"

// default constructor
FileIOException::FileIOException()
: RuntimeException()
{
}

// variable constructor
FileIOException::FileIOException(const std::string& err)
: RuntimeException(err)
{
}

// copy constructor
FileIOException::FileIOException(const FileIOException& fileIOException)
: RuntimeException(fileIOException)
{
}

// destructor (is trivial)
FileIOException::~FileIOException()
= default;
