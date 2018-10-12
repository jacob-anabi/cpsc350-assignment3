/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#ifndef INVALIDSTACKOPERATIONEXCEPTION_H
#define INVALIDSTACKOPERATIONEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class InvalidStackOperationException : public RuntimeException
{
public:
    /**
     * default constructor
     */
    InvalidStackOperationException();
    /**
     * variable constructor
     * @param err - the error message
     */
    explicit InvalidStackOperationException(const std::string& err);
    /**
     * copy constructor
     * @param invalidStackOperationException - the InvalidStackOperationException to copy over
     */
    InvalidStackOperationException(const InvalidStackOperationException& invalidStackOperationException);
    /**
      * destructor
      * NOTE: trivial
      */
    ~InvalidStackOperationException() override;
};


#endif // INVALIDSTACKOPERATIONEXCEPTION_H
