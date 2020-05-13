#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Vector.h"
#include "Exceptions.h"
#include <time.h>

template <typename Type>
Vector<Type>::Vector()
{
    countOfElements = 0;
    memoryAllocation(countOfElements);
}

template <typename Type>
Vector<Type>::Vector(int countOfNeedElements)
{
    checkSize(countOfNeedElements, __LINE__);
    countOfElements = countOfNeedElements;
    
    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);
    
    myIterator<Type> iter(*this);
    for (;iter; iter++)
        *iter = 0;
}

template <typename Type>
Vector<Type>::Vector(int countOfNeedElements, Type *lastVector)
{
    checkSize(countOfNeedElements, __LINE__);
    countOfElements = countOfNeedElements;
    
    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);
    
    myIterator<Type> iter(*this);
    for (; iter; iter++)
        *iter = lastVector[iter.curIndex];
}

template <typename Type>
Vector<Type>::Vector(std::initializer_list<Type> args)
{
    if (args.size() == 0)   
        Vector();

    countOfElements = int(args.size());
    
    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);

    myIterator<Type> iter(*this);
    for (auto &element : args)
    {
        *iter = element;
        iter++;
    }
}

template <typename Type>
Vector<Type>::~Vector<Type>()
{
    data.reset();
}

template <typename Type>
bool Vector<Type>::isEmpty() const
{
    return countOfElements == 0;
}

template <typename Type>
int Vector<Type>::getSize() const
{
    return countOfElements;
}

template <typename Type>
Type& Vector<Type>::operator[](int curIndex)
{
    return getNeedElement(curIndex);
}

template <typename Type>
const Type& Vector<Type>::operator[](int curIndex) const
{
    return getNeedElement(curIndex);
}

template <typename Type>
Type& Vector<Type>::getNeedElement(int curIndex)
{
    checkIndex(curIndex, __LINE__);
    myIterator<Type> iter(*this);
    for (int i = 0; i < curIndex; i++)
        iter++;
    return *iter;
}

template <typename Type>
const Type& Vector<Type>::getNeedElement(int curIndex) const
{
    checkIndex(curIndex, __LINE__);
    myIterator<Type> iter(*this);
    for (int i = 0; i < curIndex; i++)
        iter++;
    return *iter;
}

template <typename Type>
void Vector<Type>::changeElement(int curIndex, const Type& number)
{
    checkIndex(curIndex, __LINE__);
    getNeedElement(curIndex) = number;
}

template <typename Type>
void Vector<Type>::pushBack(const Type& number)
{
    int newCountOfElements = countOfElements + 1;
    Vector<Type> newVector(newCountOfElements);
    myIterator<Type> iter(*this);
    myIterator<Type> newIter(newVector);
    for (; iter; iter++, newIter++)
        *newIter = *iter;
    *newIter = number;
    *this = newVector;
}

template <typename Type>
Type Vector<Type>::pop()
{
    checkSize(countOfElements, __LINE__);
    int newCountOfElements = countOfElements - 1;
    Vector<Type> newVector(newCountOfElements);
    myIterator<Type> iter(*this);
    myIterator<Type> newIter(newVector);
    for (; newIter; iter++, newIter++)
        *newIter = *iter;
    Type lastNum = *iter;
    *this = newVector;
    return lastNum;
}

template <typename Type>
int Vector<Type>::getIndex(const Type& number)
{
    myIterator<Type> iter(*this);
    for (; iter; iter++)
        if (*iter == number)
            return (iter.getCurIndex());
    return -1; 
}

template <typename Type>
Type Vector<Type>::sumOfElements()
{
    checkSize(countOfElements, __LINE__);
    Type curSum = 0;
    myIterator<Type> iter(*this);
    for (; iter; iter++)
        curSum += *iter;
    return curSum;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector<Type>& curVector)
{
    checkSize(curVector.countOfElements, __LINE__);
    countOfElements = curVector.countOfElements;

    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);

    myIterator<Type> newIter(*this);
    myIterator<Type> curIter(curVector);
    for (; newIter; newIter++, curIter++)
        *newIter = *curIter;
    
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(std::initializer_list<Type> args)
{
    countOfElements = int(args.size());
    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);
    myIterator<Type> iter(*this);
    for (auto &element : args)
    {
        *iter = element;
        iter++;
    }
    return *this;
}

int max(int first, int second)
{
    if (first > second)
        return first;
    return second;
}

template <typename Type>
Type Vector<Type>::operator *(const Vector<Type>& curVector) const
{
    checkSize(curVector.countOfElements, __LINE__);
    Vector<Type> resVector(max(countOfElements, curVector.countOfElements));
    multOfVectors(resVector, *this, curVector);
    return resVector.sumOfElements();
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    Vector<Type> resVector(max(countOfElements, curVector.countOfElements));
    sumOfVectors(resVector, *this, curVector);
    return resVector;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator+=(const Vector<Type>& curVector)
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    sumOfVectors(*this, *this, curVector);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    Vector<Type> resVector(max(countOfElements, curVector.countOfElements));
    diffOfVectors(resVector, *this, curVector);
    return resVector;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator-=(const Vector<Type>& curVector)
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    diffOfVectors(*this, *this, curVector);
    return *this;
}

template <typename Type>
bool Vector<Type>::operator==(const Vector<Type>& curVector) const
{
    if (countOfElements != curVector.countOfElements)
        return false;
    bool flag = true;
    myIterator<Type> firstIter(*this);
    myIterator<Type> secondIter(curVector);
    for (; firstIter && flag; firstIter++, secondIter++)
        if (*firstIter != *secondIter)
            flag = false;
    return flag;
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type>& curVector) const
{
    if (*this == curVector)
        return false;
    return true;
}

template <typename Type>
void  Vector<Type>::sumOfVectors(Vector<Type>& resVector, const Vector<Type>& firstVector, const Vector<Type>& secondVector) const
{
    myIterator<Type> iterForRes(resVector);
    myIterator<Type> iterForFirst(firstVector);
    myIterator<Type> iterForSecond(secondVector);
    for (int i = 0; iterForRes; i++, iterForRes++, iterForFirst++, iterForSecond++)
    {
        if (i >= iterForFirst.getSize())
            *iterForRes = *iterForSecond;
        else if (i >= iterForSecond.getSize())
            *iterForRes = *iterForFirst;
        else
            *iterForRes = *iterForFirst + *iterForSecond;
    }
}

template <typename Type>
void  Vector<Type>::multOfVectors(Vector<Type>& resVector, const Vector<Type>& firstVector, const Vector<Type>& secondVector) const
{
    myIterator<Type> iterForRes(resVector);
    myIterator<Type> iterForFirst(firstVector);
    myIterator<Type> iterForSecond(secondVector);
    for (int i = 0; iterForRes; i++, iterForRes++, iterForFirst++, iterForSecond++)
    {
        if (i >= iterForFirst.getSize() || i >= iterForSecond.getSize())
            *iterForRes = 0;
        else
            *iterForRes = *iterForFirst * *iterForSecond;
    }
}

template <typename Type>
void  Vector<Type>::diffOfVectors(Vector<Type>& resVector, const Vector<Type>& firstVector, const Vector<Type>& secondVector) const
{
    myIterator<Type> iterForRes(resVector);
    myIterator<Type> iterForFirst(firstVector);
    myIterator<Type> iterForSecond(secondVector);
    for (int i = 0; iterForRes; i++, iterForRes++, iterForFirst++, iterForSecond++)
    {
        if (i >= iterForFirst.getSize())
            *iterForRes = -*iterForSecond;
        else if (i >= iterForSecond.getSize())
            *iterForRes = *iterForFirst;
        else
            *iterForRes = *iterForFirst - *iterForSecond;
    }
}

template <typename Type>
void Vector<Type>::memoryAllocation(int countOfNeedElements)
{
    data.reset();
    std::shared_ptr<Type> sp(new Type[countOfNeedElements], std::default_delete<Type[]>());
    data = sp;
}

template <typename Type>
bool Vector<Type>::checkSize(int curSize, int line) const
{
    if (curSize != 0)
        return true;
    time_t curTime = time(NULL);
    throw emptyVectorException(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

template <typename Type>
bool Vector<Type>::checkAllocation(int line) const
{
    if (data)
        return true;
    time_t curTime = time(NULL);
    throw memoryAllocationException(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

template <typename Type>
bool Vector<Type>::checkIndex(int index, int line) const
{
    if (index >= 0 || index < countOfElements)
        return true;
    time_t curTime = time(NULL);
    throw indexIsOutOfRange(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

#endif // VECTOR_HPP
