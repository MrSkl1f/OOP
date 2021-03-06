#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Iterator.h"
#include "Exceptions.h"

template <typename Type>
MyIterator<Type>::MyIterator(const MyIterator<Type>& curIterator)
{
    currentPtr = curIterator.currentPtr;
    size = curIterator.size;
    curIndex = curIterator.curIndex;
}

template <typename Type>
MyIterator<Type>::MyIterator(const Vector<Type>& curVector)
{
    currentPtr = curVector.data;
    size = curVector.countOfElements;
    curIndex = 0;
}

template <typename Type>
Type& MyIterator<Type>::operator*()
{
    checkLine(__LINE__);
    std::shared_ptr<Type[]> copyPtr = currentPtr.lock();
    return *(copyPtr.get() + curIndex);
}

template <typename Type>
Type* MyIterator<Type>::operator->()
{
    checkLine(__LINE__);
    std::shared_ptr<Type[]> copyPtr = currentPtr.lock();
    return (copyPtr.get() + curIndex);
}

template <typename Type>
const Type& MyIterator<Type>::operator*() const
{
    checkLine(__LINE__);
    std::shared_ptr<Type[]> copyPtr = currentPtr.lock();
    return *(copyPtr.get() + curIndex);
}

template <typename Type>
const Type* MyIterator<Type>::operator->() const
{
    checkLine(__LINE__);
    std::shared_ptr<Type[]> copyPtr = currentPtr.lock();
    return (copyPtr.get() + curIndex);
}

template <typename Type>
MyIterator<Type>::operator bool() const
{
    checkLine(__LINE__);
    if (curIndex >= size || curIndex < 0 || size == 0)
        return false;
    return true;
}

template<class Type>
MyIterator<Type>& MyIterator<Type>::operator=(const MyIterator<Type>& curIterator)
{
    checkLine(__LINE__);
    currentPtr = curIterator.currentPtr;
    return *this;
}

template <typename Type>
MyIterator<Type>& MyIterator<Type>::operator+=(int n)
{
    checkLine(__LINE__);
    currentPtr += n;
    return *this;
}

template <typename Type>
MyIterator<Type> MyIterator<Type>::operator+(int n) const
{
    checkLine(__LINE__);
    MyIterator<Type> newIter(*this);
    newIter += n;
    return newIter;
}

template <typename Type>
MyIterator<Type>& MyIterator<Type>::operator++()
{
    checkLine(__LINE__);
    ++curIndex;
    return *this;
}

template <typename Type>
MyIterator<Type> MyIterator<Type>::operator++(int)
{
    checkLine(__LINE__);
    ++(*this);
    return *this;
}

template <typename Type>
MyIterator<Type>& MyIterator<Type>::operator-=(int n)
{
    checkLine(__LINE__);
    currentPtr -= n;
    return *this;
}

template <typename Type>
MyIterator<Type> MyIterator<Type>::operator-(int n) const
{
    checkLine(__LINE__);
    MyIterator<Type> newIter(*this);
    newIter -= n;
    return newIter;
}

template <typename Type>
MyIterator<Type>& MyIterator<Type>::operator--()
{
    checkLine(__LINE__);
    --curIndex;
    return *this;
}

template <typename Type>
MyIterator<Type> MyIterator<Type>::operator--(int)
{
    checkLine(__LINE__);
    --(*this);
    return *this;
}

template <typename Type>
int MyIterator<Type>::getCurIndex()
{
    return curIndex;
}

template <typename Type>
int MyIterator<Type>::getSize()
{
    return size;
}

template <typename Type>
bool MyIterator<Type>::operator==(const MyIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() == curIterator.currentPtr.lock();
}

template <typename Type>
bool MyIterator<Type>::operator!=(const MyIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() != curIterator.currentPtr.lock();
}

template <typename Type>
bool MyIterator<Type>::operator<(const MyIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() < curIterator.currentPtr.lock();
}

template <typename Type>
bool MyIterator<Type>::operator<=(const MyIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() <= curIterator.currentPtr.lock();
}

template <typename Type>
bool MyIterator<Type>::operator>(const MyIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() > curIterator.currentPtr.lock();
}

template <typename Type>
bool MyIterator<Type>::operator>=(const MyIterator<Type>& curIterator) const
{
    checkLine(__LINE__);
    return currentPtr.lock() >= curIterator.currentPtr.lock();
}

template <typename Type>
bool MyIterator<Type>::checkLine(int line) const
{
    if (!currentPtr.expired())
        return true;

    time_t curTime = time(NULL);
    throw expiredWeakPtrException(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    return false;
}

#endif // ITERATOR_HPP
