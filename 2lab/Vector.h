#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>
#define EPSILON 1e-5
#include "Iterator.hpp"
#include "ConstIterator.hpp"
#include "BaseVector.h"

template <typename Type>
class Vector: BaseVector
{
public:
    friend class MyIterator<Type>;
    friend class MyConstIterator<Type>;

    Vector();

    explicit Vector(int countOfNeedElements);
    Vector(int countOfNeedElements, Type *lastVector);
    Vector(std::initializer_list<Type> args);
    explicit Vector(const Vector<Type>& curVector);
    Vector(Vector<Type>&& curVector) noexcept;
    ~Vector();

    bool isEmpty() const override;
    int getSize() const override;

    Type& operator [](int curIndex);
    Type& getNeedElement(int curIndex);
    const Type& operator [](int curIndex) const;
    const Type& getNeedElement(int curIndex) const;

    void changeElement(int curIndex, const Type& number); //setElem

    MyIterator<Type> begin() { return MyIterator<Type> (*this); };
    MyIterator<Type> end() { return MyIterator<Type> (*this ) + this->countOfElements; };

    MyConstIterator<Type> begin() const { return MyConstIterator<Type> (*this); };
    MyConstIterator<Type> end() const { return MyConstIterator<Type> (*this ) + this->countOfElements; };

    MyConstIterator<Type> cbegin() const { return MyConstIterator<Type> (*this); };
    MyConstIterator<Type> cend() const { return MyConstIterator<Type> (*this ) + this->countOfElements; }; 

    Vector<Type>& operator =(const Vector<Type>& curVector);
    Vector<Type>& operator =(Vector<Type> &&curVector);
    Vector<Type>& operator =(std::initializer_list<Type> args);

    // Скалярное произведение
    Type operator &(const Vector<Type>& curVector) const; 
    Type scalarMult(const Vector<Type>& secondVector) const;

    // Обычное произведение
    Vector<Type> operator *(const Vector<Type>& curVector) const;
    Vector<Type> operator *(const Type& curNum) const;
    Vector<Type>& operator *=(const Vector<Type>& curVector);
    Vector<Type>& operator *=(const Type& curNum);
    Vector<Type> multOnVector(const Vector<Type>& curVector) const;
    Vector<Type> multOnNumber(const Type& curNum) const; 

    // Обычное деление
    Vector<Type> operator /(const Vector<Type>& curVector) const;
    Vector<Type> operator /(const Type& curNum) const;
    Vector<Type>& operator /=(const Vector<Type>& curVector);
    Vector<Type>& operator /=(const Type& curNum);
    Vector<Type> divOnVector(const Vector<Type>& curVector) const;
    // метод деления на число

    //  Обычное сложение
    Vector<Type> operator +(const Vector<Type>& curVector) const;
    Vector<Type> operator +(const Type&curNum) const;
    Vector<Type>& operator +=(const Vector<Type>& curVector);
    Vector<Type>& operator +=(const Type& curNum);
    Vector<Type> sumOfVectors(const Vector<Type>& secondVector) const;
    Vector<Type> sumWithNumber(const Type& curNum) const; 

    // Обычное вычитание
    Vector<Type> operator -(const Vector<Type>& curVector) const;
    Vector<Type> operator -(const Type&curNum) const;
    Vector<Type>& operator -=(const Vector<Type>& curVector);
    Vector<Type>& operator -=(const Type& curNum);
    Vector<Type> diffOfVectors(const Vector<Type>& secondVector) const;
    Vector<Type> diffWithNumber(const Type& curNum) const; 
    
    // Векторное произведение
    Type sumOfVectMult(const Vector<Type>& curVector) const;
    Vector<Type> operator %(const Vector<Type>& curVector) const;
    Vector<Type>& operator %=(const Vector<Type>& curVector);
    Vector<Type> vectMult(const Vector<Type>& curVector) const;

    bool operator ==(const Vector<Type>& curVector) const;
    bool isEqual(const Vector<Type>& curVector) const;
    bool operator !=(const Vector<Type>& curVector) const;
    bool isNotEqual(const Vector<Type>& curVector) const;
    
    //единичный вектор 
    Vector<Type> getSingleVect() const;
    bool isSingleVect() const;

    double getAngle(const Vector<Type>& curVector) const;
    bool isOrthogonality(const Vector<Type>& curVector) const;
    bool isCollinearity(const Vector<Type>& curVector) const;
    
    Type len(void) const;
    bool isZero() const;

protected:
    bool checkSizes(int sizeFirst, int sizeSecond, int line) const;
    bool checkSize(int curSize, int line) const;
    bool checkAllocation(int line) const;
    bool checkIndex(int index, int line) const;
    bool checkDiv(const Vector<Type>& curVector, int line) const;
    bool checkZero(const Type& curNum, int line) const;
    bool checkVectMult(int sizeFirst, int sizeSecond, int line) const;

    void memoryAllocation(int countOfNeedElements);
private:
    std::shared_ptr<Type[]> data;
};

template<typename Type>
std::ostream& operator <<(std::ostream& os, const Vector<Type>& vec)
{
    MyIterator<Type> iter(vec);
    for (; iter; iter++)
        os << ' ' << *iter ;
    return os;
}

#endif // VECTOR_H
