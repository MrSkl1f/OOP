#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "BaseExceptions.h"

class memoryAllocationException : public BaseExceptions
{
public:
    memoryAllocationException(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Memory allocation exception.") :
    BaseExceptions(fileName, className, curLine, curTime, curInfo) {};

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class emptyVectorException : public BaseExceptions
{
public:
    emptyVectorException(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Vector is empty.") :
    BaseExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class indexIsOutOfRange : public BaseExceptions
{
public:
    indexIsOutOfRange(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Invalid index.") :
    BaseExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class expiredWeakPtrException : public BaseExceptions
{
public:
    expiredWeakPtrException(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Expired weak pointer.") :
    BaseExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

#endif // EXCEPTIONS_H
