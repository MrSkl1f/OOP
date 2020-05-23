#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "BaseExceptions.h"

class memoryAllocationException : public VectorExceptions
{
public:
    memoryAllocationException(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Memory allocation exception.") :
    VectorExceptions(fileName, className, curLine, curTime, curInfo) {};

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class emptyVectorException : public VectorExceptions
{
public:
    emptyVectorException(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Vector is empty.") :
    VectorExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class notSameSizes : public VectorExceptions
{
public:
    notSameSizes(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Not same sizes.") :
    VectorExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class indexIsOutOfRange : public VectorExceptions
{
public:
    indexIsOutOfRange(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Invalid index.") :
    VectorExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class expiredWeakPtrException : public VectorExceptions
{
public:
    expiredWeakPtrException(const std::string& fileName, const std::string& className, 
        const int curLine, const char* curTime, const std::string& curInfo = "Expired weak pointer.") :
    VectorExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class divisionByZero : public VectorExceptions
{
public:
    divisionByZero(const std::string& fileName, const std::string& className,
        const int curLine, const char* curTime, const std::string& curInfo = "Division by zero.") :
    VectorExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class vectMultException : public VectorExceptions
{
public:
    vectMultException(const std::string& fileName, const std::string& className,
        const int curLine, const char* curTime, const std::string& curInfo = "Vector should consist of 3 elements.") :
    VectorExceptions(fileName, className, curLine, curTime, curInfo) {};
    
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

#endif // EXCEPTIONS_H
