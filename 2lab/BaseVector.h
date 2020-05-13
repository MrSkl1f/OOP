#ifndef BASEVECTOR_H
#define BASEVECTOR_H

template<typename Type>
class myIterator;

class BaseVector
{
public:
    BaseVector();
    BaseVector(const BaseVector& lastVector);
    ~BaseVector();

    virtual bool isEmpty() const = 0;
    virtual int getSize() const = 0;
protected:
    int countOfElements;
};

#endif // BASEVECTOR_H
