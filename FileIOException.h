/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#ifndef FILEIOEXCEPTION_H
#define FILEIOEXCEPTION_H

#include "RuntimeException.h"

class FileIOException : public RuntimeException
{
public:
    /**
     * default constructor
     */
    FileIOException();
    /**
     * variable constructor
     * @param err - the error message
     */
    explicit FileIOException(const std::string& err);
    /**
     * copy constructor
     * @param FileIOException - the FileIOException to copy over
     */
    FileIOException(const FileIOException& fileIOException);
    /**
      * destructor
      * NOTE: trivial
      */
    ~FileIOException() override;
};

#endif // FILEIOEXCEPTION_H