#include "errors.h"


BaseException::BaseException(string message)
{
    this->message = message;
}

BaseException::BaseException(const char *message)
{
    string s(message);
    this->message = s;
}

void BaseException::show_message()
{
    cerr << message << endl;
}

FileHandlerException::FileHandlerException(const char *message): BaseException(message)
{}

FileHandlerException::FileHandlerException(string message): BaseException(message)
{}
