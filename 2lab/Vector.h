#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

#include "Iterator.hpp"
#include "BaseVector.h"

template <typename Type>
class Vector: BaseVector
{
public:
    friend class myIterator<Type>;

    Vector();

    Vector(int countOfNeedElements);
    Vector(int countOfNeedElements, Type *lastVector);
    Vector(std::initializer_list<Type> args);
    ~Vector();

    bool isEmpty() const override;
    int getSize() const override;

    Type& operator [](int curIndex);
    const Type& operator [](int curIndex) const;

    Type& getNeedElement(int curIndex);
    const Type& getNeedElement(int curIndex) const;

    void changeElement(int curIndex, const Type& number);

    void pushBack(const Type& number);
    Type pop();

    int getIndex(const Type& number);

    Type sumOfElements();
    
    Vector<Type>& operator =(const Vector<Type>& curVector);
    Vector<Type>& operator =(std::initializer_list<Type> args);

    Type operator *(const Vector<Type>& curVector) const; 

    Vector<Type> operator +(const Vector<Type>& curVector) const;
    Vector<Type>& operator +=(const Vector<Type>& curVector);
    Vector<Type> operator -(const Vector<Type>& curVector) const;
    Vector<Type>& operator -=(const Vector<Type>& curVector);

    bool operator ==(const Vector<Type>& curVector) const;
    bool operator !=(const Vector<Type>& curVector) const;

protected:
    void sumOfVectors(Vector<Type>& resVector, const Vector<Type>& firstVector, const Vector<Type>& secondVector) const;
    void multOfVectors(Vector<Type>& resVector, const Vector<Type>& firstVector, const Vector<Type>& secondVector) const;
    void diffOfVectors(Vector<Type>& resVector, const Vector<Type>& firstVector, const Vector<Type>& secondVector) const;
    void memoryAllocation(int countOfNeedElements);

    bool checkSize(int curSize, int line) const;
    bool checkAllocation(int line) const;
    bool checkIndex(int index, int line) const;
private:
    std::shared_ptr<Type> data;
};

template<typename Type>
std::ostream& operator <<(std::ostream& os, const Vector<Type>& vec)
{
    myIterator<Type> iter(vec);
    for (; iter; iter++)
        os << ' ' << *iter ;
    return os;
}

#endif // VECTOR_H
