#include "BaseVector.h"

BaseVector::BaseVector()
{
    countOfElements = 0;
}

BaseVector::BaseVector(const BaseVector& lastVector)
{
    countOfElements = lastVector.countOfElements;
}

BaseVector::~BaseVector()
{
    countOfElements = 0;
}
