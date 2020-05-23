#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H

#include <memory>
#include <time.h>

template<typename Type>
class Vector;

template <typename Type>
class MyConstIterator : public std::iterator<std::forward_iterator_tag, Type>
{
public:
    MyConstIterator(const MyConstIterator<Type>& curIterator);
    MyConstIterator(const Vector<Type>& curVector);

    const Type& operator*() const;
    const Type* operator->() const;
    operator bool() const;

    MyConstIterator<Type>& operator=(const MyConstIterator<Type>& curIterator);

    MyConstIterator<Type>& operator+=(int n);
    MyConstIterator<Type> operator+(int n) const;
    MyConstIterator<Type>& operator++();
    MyConstIterator<Type> operator++(int);

    MyConstIterator<Type>& operator-=(int n);
    MyConstIterator<Type> operator-(int n) const;
    MyConstIterator<Type>& operator--();
    MyConstIterator<Type> operator--(int);

    int getCurIndex();
    int getSize();

    bool operator==(const MyConstIterator<Type>& curIterator) const;
    bool operator!=(const MyConstIterator<Type>& curIterator) const;
    bool operator<(const MyConstIterator<Type>& curIterator) const;
    bool operator<=(const MyConstIterator<Type>& curIterator) const;
    bool operator>(const MyConstIterator<Type>& curIterator) const;
    bool operator>=(const MyConstIterator<Type>& curIterator) const;

    bool checkLine(int line) const;
protected:
    int size;
    int curIndex;
private:
    std::weak_ptr<Type[]> currentPtr;
};

#endif // CONSTITERATOR_H
