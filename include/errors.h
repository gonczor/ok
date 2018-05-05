#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <iostream>
#include <string>

#include "errors.h"

using namespace std;

class BaseException:  public exception
{
protected:
    string message;
public:
    BaseException(string message);
    BaseException(const char *message);
    void show_message();
};

class FileHandlerException: public BaseException
{
public:
    FileHandlerException(const char *message);
    FileHandlerException(string message);
};

#endif
