#ifndef CONSTITERATOR_HPP
#define CONSTITERATOR_HPP

#include "ConstIterator.h"
#include "Exceptions.h"

template <typename Type>
MyConstIterator<Type>::MyConstIterator(const MyConstIterator<Type>& curIterator)
{
    currentPtr = curIterator.currentPtr;
    size = curIterator.size;
    curIndex = curIterator.curIndex;
}

template <typename Type>
MyConstIterator<Type>::MyConstIterator(const Vector<Type>& curVector)
{
    currentPtr = curVector.data;
    size = curVector.countOfElements;
    curIndex = 0;
}

template <typename Type>
const Type& MyConstIterator<Type>::operator*() const
{
    checkLine(__LINE__);
    std::shared_ptr<Type[]> copyPtr = currentPtr.lock();
    return *(copyPtr.get() + curIndex);
}

template <typename Type>
const Type* MyConstIterator<Type>::operator->() const
{
    checkLine(__LINE__);
    std::shared_ptr<Type[]> copyPtr = currentPtr.lock();
    return (copyPtr.get() + curIndex);
}

template <typename Type>
MyConstIterator<Type>::operator bool() const
{
    checkLine(__LINE__);
    if (curIndex >= size || curIndex < 0 || size == 0)
        return false;
    return true;
}

template<class Type>
MyConstIterator<Type>& MyConstIterator<Type>::operator=(const MyConstIterator<Type>& curIterator)
{
    checkLine(__LINE__);
    currentPtr = curIterator.currentPtr;
    return *this;
}

template <typename Type>
MyConstIterator<Type>& MyConstIterator<Type>::operator+=(int n)
{
    checkLine(__LINE__);
    currentPtr += n;
    return *this;
}

template <typename Type>
MyConstIterator<Type> MyConstIterator<Type>::operator+(int n) const
{
    checkLine(__LINE__);
    MyConstIterator<Type> newIter(*this);
    newIter += n;
    return newIter;
}

template <typename Type>
MyConstIterator<Type>& MyConstIterator<Type>::operator++()
{
    checkLine(__LINE__);
    ++curIndex;
    return *this;
}

template <typename Type>
MyConstIterator<Type> MyConstIterator<Type>::operator++(int)
{
    checkLine(__LINE__);
    ++(*this);
    return *this;
}

template <typename Type>
MyConstIterator<Type>& MyConstIterator<Type>::operator-=(int n)
{
    checkLine(__LINE__);
    currentPtr -= n;
    return *this;
}

template <typename Type>
MyConstIterator<Type> MyConstIterator<Type>::operator-(int n) const
{
    checkLine(__LINE__);
    MyConstIterator<Type> newIter(*this);
    newIter -= n;
    return newIter;
}

template <typename Type>
MyConstIterator<Type>& MyConstIterator<Type>::operator--()
{
    checkLine(__LINE__);
    --curIndex;
    return *this;
}

template <typename Type>
MyConstIterator<Type> MyConstIterator<Type>::operator--(int)
{
    checkLine(__LINE__);
    --(*this);
    return *this;
}

template <typename Type>
int MyConstIterator<Type>::getCurIndex()
{
    return curIndex;
}

template <typename Type>
int MyConstIterator<Type>::getSize()
{
    return size;
}

template <typename Type>
bool MyConstIterator<Type>::operator==(const MyConstIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() == curIterator.currentPtr.lock();
}

template <typename Type>
bool MyConstIterator<Type>::operator!=(const MyConstIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() != curIterator.currentPtr.lock();
}

template <typename Type>
bool MyConstIterator<Type>::operator<(const MyConstIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() < curIterator.currentPtr.lock();
}

template <typename Type>
bool MyConstIterator<Type>::operator<=(const MyConstIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() <= curIterator.currentPtr.lock();
}

template <typename Type>
bool MyConstIterator<Type>::operator>(const MyConstIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() > curIterator.currentPtr.lock();
}

template <typename Type>
bool MyConstIterator<Type>::operator>=(const MyConstIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() >= curIterator.currentPtr.lock();
}

template <typename Type>
bool MyConstIterator<Type>::checkLine(int line) const
{
    if (!currentPtr.expired())
        return true;

    time_t curTime = time(NULL);
    throw expiredWeakPtrException(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

#endif // CONSTITERATOR_HPP
