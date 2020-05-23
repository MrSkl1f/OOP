#ifndef VectorExceptions_H
#define VectorExceptions_H

#include <iostream>
#include <exception>

// название
class VectorExceptions : public std::exception
{
public:
    explicit VectorExceptions(const std::string& fileName,
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

VectorExceptions::VectorExceptions(const std::string& fileName, const std::string& className,
                                              const int curLine, const char* curTime, const std::string& curInfo)
{
    errInfo = "\nException in: \nFile: " + fileName + "\nClass: " + className + "\nLine: " +
    std::to_string(curLine) + "\nAt time: " + curTime + "Exception: " + curInfo;
}
#endif // VectorExceptions_H
