/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#include "InvalidStackOperationException.h"

// default constructor
InvalidStackOperationException::InvalidStackOperationException()
: RuntimeException()
{
}

// variable constructor
InvalidStackOperationException::InvalidStackOperationException(const std::string& err)
: RuntimeException(err)
{
}

// copy constructor
InvalidStackOperationException::InvalidStackOperationException(const InvalidStackOperationException& invalidStackOperationException)
: RuntimeException(invalidStackOperationException)
{
}

// destructor (is trivial)
InvalidStackOperationException::~InvalidStackOperationException()
= default;
