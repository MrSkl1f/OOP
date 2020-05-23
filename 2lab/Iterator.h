#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <time.h>

template<typename Type>
class Vector;

template <typename Type>
class MyIterator : public std::iterator<std::forward_iterator_tag, Type>
{
public:
    MyIterator(const MyIterator<Type>& curIterator);
    MyIterator(const Vector<Type>& curVector);
    // const
    Type& operator*();
    Type* operator->();
    const Type& operator*() const;
    const Type* operator->() const;
    operator bool() const;

    MyIterator<Type>& operator=(const MyIterator<Type>& curIterator);

    MyIterator<Type>& operator+=(int n);
    MyIterator<Type> operator+(int n) const;
    MyIterator<Type>& operator++();
    MyIterator<Type> operator++(int);

    MyIterator<Type>& operator-=(int n);
    MyIterator<Type> operator-(int n) const;
    MyIterator<Type>& operator--();
    MyIterator<Type> operator--(int);

    int getCurIndex();
    int getSize();

    bool operator==(const MyIterator<Type>& curIterator) const;
    bool operator!=(const MyIterator<Type>& curIterator) const;
    bool operator<(const MyIterator<Type>& curIterator) const;
    bool operator<=(const MyIterator<Type>& curIterator) const;
    bool operator>(const MyIterator<Type>& curIterator) const;
    bool operator>=(const MyIterator<Type>& curIterator) const;
    
    bool checkLine(int line) const;
protected:
    int size;
    int curIndex;
private:
    std::weak_ptr<Type[]> currentPtr;
};

#endif // ITERATOR_H
