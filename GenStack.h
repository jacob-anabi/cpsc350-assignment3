/**
 * @author Jacob Anabi
 * @date 2018-10-11
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 3 - Syntax Checker
 */

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "InvalidStackOperationException.h"

template <class T>
class GenStack
{
public:
    /**
     * default constructor
     */
    GenStack();
    /**
     * variable constructor
     * @param size - the size of the stack (only positive ints)
     */
    explicit GenStack(unsigned int size);
    /**
     * copy constructor
     * @param genStack - the stack to copy over
     */
    GenStack(const GenStack& genStack);
    /**
     * destructor
     */
    ~GenStack();

    /**
     * pushes an element on the top of the stack
     * @param elem - the element to push
     */
    void push(T elem);

    /**
     * pops the top element off of the stack
     * @return - the top element that is pushed off
     */
    T pop();

    /**
     * peeks at the top element of the stack
     * @return - the top element of the stack
     */
    T peek();

    /**
     * checks if the stack is full
     * @return - a boolean value that returns true if the stack is full, false otherwise
     */
    bool isFull();

    /**
     * checks if the stack is empty
     * @return - a boolean value that returns true if the stack is empty, false otherwise
     */
    bool isEmpty();

    // TODO: implement operator overloading

private:
    unsigned int size; // the size of the stack
    int top; // the index of the array that represents the top of the stack

    T* stackArr; // the array to use for the stack
    T* tempExtArr; // the temporary array to use for stack extension

    /**
     * extends the size of the stack if it is full
     */
    void extendFullStack();
};

// default constructor
template<class T>
GenStack<T>::GenStack()
: stackArr(new T[5]), tempExtArr(nullptr), size(5), top(-1) // default stack size is 5
{
}

// variable constructor
template<class T>
GenStack<T>::GenStack(unsigned int size)
: stackArr(new T[size]), tempExtArr(nullptr), size(size), top(-1) // stack starts of empty
{
}

// copy constructor
template<class T>
GenStack<T>::GenStack(const GenStack& genStack)
: stackArr(new T[genStack.size]), tempExtArr(nullptr), size(genStack.size), top(genStack.top)
{
    for (int i = 0; i <= top; ++i)
    {
        stackArr[i] = genStack.stackArr[i]; // copy each element from genStack to our stack
    }
}

// destructor
template<class T>
GenStack<T>::~GenStack()
{
    delete[] stackArr;
    delete[] tempExtArr;
}

// pushes an element on the top of the stack
template<class T>
void GenStack<T>::push(T elem)
{
    if (isFull()) // if the stack is full, extend it
    {
        extendFullStack();
    }

    stackArr[++top] = elem; // popping elem to the top of the stack
}

// pops the top element off of the stack
template<class T>
T GenStack<T>::pop()
{
    if (isEmpty())
    {
        throw InvalidStackOperationException("Pop operation performed on empty stack.");
    }
    return stackArr[top--]; // return the element at the top, then decrement the top
}

// peeks at the top element of the stack
template<class T>
T GenStack<T>::peek()
{
    if (isEmpty())
    {
        throw InvalidStackOperationException("Peek operation performed on empty stack.");
    }
    return stackArr[top]; // return the element at the top of the stack
}

// checks if the stack is full
template<class T>
bool GenStack<T>::isFull()
{
    return (top == size - 1);
}

// checks if the stack is empty
template<class T>
bool GenStack<T>::isEmpty()
{
    return (top == -1);
}

// extends the size of the stack if it is full
template<class T>
void GenStack<T>::extendFullStack()
{
    tempExtArr = new T[++size];

    for (int i = 0; i <= top; ++i)
    {
        tempExtArr[i] = stackArr[i]; // copy every element from our current stack array to the larger stack array
    }

    delete[] stackArr; // delete the old array
    stackArr = tempExtArr; // point our current stack array to the extended array
    tempExtArr = nullptr; // point our temp array to nullptr
}

#endif // GENSTACK_H