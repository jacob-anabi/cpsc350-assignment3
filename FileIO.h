/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <fstream>

class FileIO
{
public:
    /**
     * variable constructor
     * @param fileName - the name of the file
     * @param operMode - what mode to operate the file in ('r' = read, 'w' = write)
     */
    FileIO(const std::string& fileName, char operMode);
    /**
     * copy constructor
     * @param fileIO - the FileIO to copy over
     */
    FileIO(const FileIO& fileIO);
    /**
     * destructor
     */
    ~FileIO();

    /**
     * changes the file you want to process
     * @param newFileName - the new name of the file
     * @param newOperMode - the new mode to operate the file in
     */
    void changeFile(const std::string& newFileName, char newOperMode);

    /**
     * reads the file line by line
     * @param line - sets the content of a file line to a string
     * @return - a boolean value that returns true if a next line can be read, false otherwise
     */
    bool readFileLine(std::string& line);

    /**
     * writes a line to a file
     * @param writeMode - what mode to write the file in ('o' = overwrite, 'a' = append, 'd' = delete contents of a file)
     */
    void writeFileLine(const std::string& line, char writeMode);

private:
    std::string fileName; // the file name
    char operMode; // the mode to operate the file in
    std::ifstream inFile; // the read file (must be a class variable to allow reading of line by line)
};

#endif // FILEIO_H