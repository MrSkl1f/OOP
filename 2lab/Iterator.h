#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <time.h>
#include "Vector.h"

template<typename Type>
class Vector;

template <typename Type>
class myIterator : public std::iterator<std::forward_iterator_tag, Type>
{
private:
    std::weak_ptr<Type> currentPtr;
public:
    myIterator(const myIterator<Type>& curIterator);
    myIterator(const Vector<Type>& curVector);

    Type& operator*();
    const Type& operator*() const;
    Type* operator->();
    const Type* operator->() const;
    operator bool() const;

    myIterator<Type>& operator=(const myIterator<Type>& curIterator);

    myIterator<Type>& operator+=(int n);
    myIterator<Type> operator+(int n) const;
    myIterator<Type>& operator++();
    myIterator<Type> operator++(int);

    myIterator<Type>& operator-=(int n);
    myIterator<Type> operator-(int n) const;
    myIterator<Type>& operator--();
    myIterator<Type> operator--(int);

    int getCurIndex();
    int getSize();

    bool operator==(const myIterator<Type>& curIterator) const;
    bool operator!=(const myIterator<Type>& curIterator) const;
    
    bool checkLine(int line) const;
protected:
    int size;
    int curIndex;
};

#endif // ITERATOR_H
