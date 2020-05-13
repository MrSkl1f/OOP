#ifndef BASEEXCEPTIONS_H
#define BASEEXCEPTIONS_H

#include <iostream>
#include <exception>

class BaseExceptions : public std::exception
{
public:
    explicit BaseExceptions(const std::string& fileName,
                                              const std::string& className,
                                              const int curLine,
                                              const char* curTime,
                                              const std::string& curInfo);
    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
protected:
    std::string errInfo;
};

BaseExceptions::BaseExceptions(const std::string& fileName, const std::string& className,
                                              const int curLine, const char* curTime, const std::string& curInfo)
{
    errInfo = "\nException in: \nFile: " + fileName + "\nClass: " + className + "\nLine: " +
    std::to_string(curLine) + "\nAt time: " + curTime + "Exception: " + curInfo;
}
#endif // BASEEXCEPTIONS_H
