#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Vector.h"
#include "Exceptions.h"
#include <time.h>
#include <cmath>

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
    
    MyIterator<Type> iter(*this);
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
    
    MyIterator<Type> iter(*this);
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

    MyIterator<Type> iter(*this);
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
    MyIterator<Type> iter(*this);
    for (int i = 0; i < curIndex; i++)
        iter++;
    return *iter;
}

template <typename Type>
const Type& Vector<Type>::getNeedElement(int curIndex) const
{
    checkIndex(curIndex, __LINE__);
    MyIterator<Type> iter(*this);
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
Vector<Type>& Vector<Type>::operator=(const Vector<Type>& curVector)
{
    checkSize(curVector.countOfElements, __LINE__);
    countOfElements = curVector.countOfElements;

    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);

    MyIterator<Type> newIter(*this);
    MyIterator<Type> curIter(curVector);
    for (; newIter; newIter++, curIter++)
        *newIter = *curIter;
    
    return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator=(Vector<Type>&& curVector)
{
    checkSize(curVector.countOfElements, __LINE__);
    countOfElements = curVector.countOfElements;

    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);
    data = curVector.data;
    curVector.data.reset();

    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(std::initializer_list<Type> args)
{
    countOfElements = int(args.size());
    memoryAllocation(countOfElements);
    checkAllocation(__LINE__);
    MyIterator<Type> iter(*this);
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
Type Vector<Type>::operator &(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    return (scalarMult(curVector));
}

template <typename Type>
Vector<Type> Vector<Type>::operator *(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    return multOnVector(curVector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator *(const Type& curNum) const
{
    checkSize(countOfElements, __LINE__);
    return  multOnNumber(curNum);
}

template <typename Type>
Vector<Type>& Vector<Type>::operator *=(const Vector<Type>& curVector)
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    *this = multOnVector(curVector);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator *=(const Type& curNum)
{
    checkSize(countOfElements, __LINE__);
    *this = multOnNumber(curNum);
    return  *this;
}

template <typename Type>
Vector<Type> Vector<Type>::multOnVector(const Vector<Type>& curVector) const
{
    Vector<Type> newVector(countOfElements);
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> secondIter(curVector);
    MyIterator<Type> newIter(newVector);
    for (; newIter; newIter++, firstIter++, secondIter++)
        *newIter = *firstIter * *secondIter;
    return newVector;
}

template <typename Type>
Vector<Type> Vector<Type>::multOnNumber(const Type& curNum) const
{
    Vector<Type> newVector(countOfElements);
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> newIter(newVector);
    for (; newIter; newIter++, firstIter++)
        *newIter = *firstIter * curNum;
    return newVector;
}

template <typename Type>
Vector<Type> Vector<Type>::operator /(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    return divOnVector(curVector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator /(const Type& curNum) const
{
    checkSize(countOfElements, __LINE__);
    checkZero(curNum, __LINE__);
    return  multOnNumber(1 / curNum);
}

template <typename Type>
Vector<Type>& Vector<Type>::operator /=(const Vector<Type>& curVector)
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    *this = divOnVector(curVector);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator /=(const Type& curNum)
{
    checkSize(countOfElements, __LINE__);
    checkZero(curNum, __LINE__);
    *this = multOnNumber(1 / curNum);
    return  *this;
}

template <typename Type>
Vector<Type> Vector<Type>::divOnVector(const Vector<Type>& curVector) const
{
    Vector<Type> newVector(countOfElements);
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> secondIter(curVector);
    MyIterator<Type> newIter(newVector);
    for (; newIter; newIter++, firstIter++, secondIter++)
    {
        checkZero(*secondIter, __LINE__);
        *newIter = *firstIter / *secondIter;
    }
    return newVector;
}

template <typename Type>
Vector<Type> Vector<Type>::operator +(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    return sumOfVectors(curVector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator +(const Type& curNum) const
{
    checkSize(countOfElements, __LINE__);
    return  sumWithNumber(curNum);
}

template <typename Type>
Vector<Type>& Vector<Type>::operator +=(const Vector<Type>& curVector)
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    *this = sumOfVectors(curVector);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator +=(const Type& curNum)
{
    checkSize(countOfElements, __LINE__);
    *this = sumWithNumber(curNum);
    return  *this;
}

template <typename Type>
Vector<Type> Vector<Type>::sumWithNumber(const Type& curNum) const
{
    Vector<Type> newVector(countOfElements);
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> newIter(newVector);
    for (; newIter; newIter++, firstIter++)
        *newIter = *firstIter + curNum;
    return newVector;
}

template <typename Type>
Vector<Type> Vector<Type>::sumOfVectors(const Vector<Type>& curVector) const
{
    Vector<Type> newVector(countOfElements);
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> secondIter(curVector);
    MyIterator<Type> newIter(newVector);
    for (; newIter; newIter++, firstIter++, secondIter++)
        *newIter = *firstIter + *secondIter;
    return newVector;
}

template <typename Type>
Vector<Type> Vector<Type>::operator -(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    return diffOfVectors(curVector);
}

template <typename Type>
Vector<Type> Vector<Type>::operator -(const Type& curNum) const
{
    checkSize(countOfElements, __LINE__);
    return  diffWithNumber(curNum);
}

template <typename Type>
Vector<Type>& Vector<Type>::operator -=(const Vector<Type>& curVector)
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    *this = diffOfVectors(curVector);
    return *this;
}

template <typename Type>
Vector<Type>& Vector<Type>::operator -=(const Type& curNum)
{
    checkSize(countOfElements, __LINE__);
    *this = diffWithNumber(curNum);
    return  *this;
}

template <typename Type>
Vector<Type> Vector<Type>::diffWithNumber(const Type& curNum) const
{
    Vector<Type> newVector(countOfElements);
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> newIter(newVector);
    for (; newIter; newIter++, firstIter++)
        *newIter = *firstIter - curNum;
    return newVector;
}

template <typename Type>
Vector<Type> Vector<Type>::diffOfVectors(const Vector<Type>& curVector) const
{
    Vector<Type> newVector(countOfElements);
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> secondIter(curVector);
    MyIterator<Type> newIter(newVector);
    for (; newIter; newIter++, firstIter++, secondIter++)
        *newIter = *firstIter - *secondIter;
    return newVector;
}

template <typename Type>
Type Vector<Type>::sumOfVectMult(const Vector<Type>& curVector) const
{
    checkSize(countOfElements, __LINE__);
    checkSize(curVector.countOfElements, __LINE__);
    checkSizes(countOfElements, curVector.countOfElements, __LINE__);
    return this->len() * curVector.len() * sin(getAngle(curVector) * M_PI / 180);
}

template <typename Type>
Vector<Type> Vector<Type>::operator %(const Vector<Type>& curVector) const
{
    checkVectMult(countOfElements, curVector.countOfElements, __LINE__);
    return vectMult(curVector);
}

template <typename Type>
Vector<Type>& Vector<Type>::operator %=(const Vector<Type>& curVector)
{
    checkVectMult(countOfElements, curVector.countOfElements, __LINE__);
    *this = vectMult(curVector);
    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::vectMult(const Vector<Type>& curVector) const
{
    Type x = data[1] * curVector.data[2] - data[2] * curVector.data[1];
    Type y = data[2] * curVector.data[0] - data[0] * curVector.data[2];
    Type z = data[0] * curVector.data[1] - data[1] * curVector.data[0];
    Vector<Type> vect = {x, y, z};
    return vect;
}

template <typename Type>
bool Vector<Type>::operator==(const Vector<Type>& curVector) const
{
    return isEqual(curVector);
}

template <typename Type>
bool Vector<Type>::isEqual(const Vector<Type>& curVector) const
{
    if (countOfElements != curVector.countOfElements)
        return false;
    bool flag = true;
    MyIterator<Type> firstIter(*this);
    MyIterator<Type> secondIter(curVector);
    for (; firstIter && flag; firstIter++, secondIter++)
        if (*firstIter != *secondIter)
            flag = false;
    return flag;
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type>& curVector) const
{
    return isNotEqual(curVector);
}

template <typename Type>
bool Vector<Type>::isNotEqual(const Vector<Type>& curVector) const
{
    if (*this == curVector)
        return false;
    return true;
}

template<typename Type>
double Vector<Type>::getAngle(const Vector<Type>& curVector) const
{
    checkDiv(curVector, __LINE__);
    double curAngle = (*this & curVector) / (this->len() * curVector.len());
    return acos(curAngle) * 180 / M_PI;
}

template <typename Type>
Vector<Type> Vector<Type>::getSingleVect() const
{
    checkSize(countOfElements, __LINE__);
    Vector<Type> newSingleVector(countOfElements);
    Type len = this->len();
    MyIterator<Type> curIter(*this);
    MyIterator<Type> newIter(newSingleVector);
    for (; newIter; curIter++, newIter++)
        *newIter = *curIter / len;
    return newSingleVector;
}

template <typename Type>
bool Vector<Type>::isSingleVect() const
{
    if (abs(this->len() - 1) < EPSILON)
        return true;
    return false;
}

template <typename Type>
bool Vector<Type>::isOrthogonality(const Vector<Type>& curVector) const
{
    if ((this->getAngle(curVector) - 90) < EPSILON)
        return true;
    return false;
}

template <typename Type>
bool Vector<Type>::isCollinearity(const Vector<Type>& curVector) const
{
    if (this->getAngle(curVector) < EPSILON)
        return true;
    return false;
}

template<typename Type>
Type Vector<Type>::len(void) const
{
    checkSize(countOfElements, __LINE__);
    MyIterator<Type> curIter(*this);
    double sum = 0;
    for (; curIter; curIter++)
        sum += *curIter * *curIter;
    return sqrt(sum);
}

template <typename Type>
bool Vector<Type>::isZero() const
{
    if (this->len() == 0)
        return true;
    return false;
}

template <typename Type>
Type Vector<Type>::scalarMult(const Vector<Type>& secondVector) const
{
    Type result = 0;
    MyIterator<Type> iterForFirst(*this);
    MyIterator<Type> iterForSecond(secondVector);
    for (; iterForFirst; iterForFirst++, iterForSecond++)
        result += *iterForFirst * *iterForSecond;
    return result;
}

template <typename Type>
void Vector<Type>::memoryAllocation(int countOfNeedElements)
{
    data.reset();
    std::shared_ptr<Type[]> sp(new Type[countOfNeedElements]);
    data = sp;
}

template <typename Type>
bool Vector<Type>::checkSizes(int sizeFirst, int sizeSecond, int line) const
{
    if (sizeFirst == sizeSecond)
        return true;
    time_t curTime = time(NULL);
    throw notSameSizes(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

template <typename Type>
bool Vector<Type>::checkSize(int curSize, int line) const
{
    if (curSize > 0)
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

template <typename Type>
bool Vector<Type>::checkZero(const Type& curNum, int line) const
{
    if (curNum)
        return true;
    time_t curTime = time(NULL);
    throw divisionByZero(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

template <typename Type>
bool Vector<Type>::checkDiv(const Vector<Type>& curVector, int line) const
{
    if (this->len() && curVector.len())
        return true;
    time_t curTime = time(NULL);
    throw divisionByZero(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

template <typename Type>
bool Vector<Type>::checkVectMult(int sizeFirst, int sizeSecond,  int line) const
{
    if (sizeFirst == 3 && sizeSecond == 3)
        return true;
    time_t curTime = time(NULL);
    throw vectMultException(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}


template <typename Type>
Vector<Type>::Vector(Vector<Type>&& curVector) noexcept : BaseVector(curVector)
{
    countOfElements = curVector.countOfElements;
    curVector.data = nullptr;
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type>& curVector) : BaseVector(curVector)
{
    *this = curVector;
}

#endif // VECTOR_HPP
