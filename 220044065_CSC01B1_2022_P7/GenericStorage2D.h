#ifndef GENERICSTORAGE2D_H_INCLUDED
#define GENERICSTORAGE2D_H_INCLUDED
#include <iostream>

template <typename T>
class GenericStorage2D
{
public:
    //No-args constructor
    GenericStorage2D();
    //Parameterized constructor
    GenericStorage2D(int intRows, int intCols, int intValue);
    //Copy constructor
    GenericStorage2D(const GenericStorage2D<T>& objOriginal);

    //Overloaded Operators
    GenericStorage2D<T>& operator=(const GenericStorage2D<T>& objRHS);\
    template <typename T1>
    friend std::ostream& operator<<(std::ostream& osLHS, GenericStorage2D<T1>& objRHS);
    bool operator==(const GenericStorage2D<T>& objRHS) const;
    bool operator!=(const GenericStorage2D<T>& objRHS) const;

    //Accessor
    int getRows() const;
    int getCols() const;
    int getValue() const;

    //Destructor
    ~GenericStorage2D();

    static const int DEFAULT_SIZE = 20;
    static const int ERROR_VALUE = -1;
    static const int DEFAULT_VALUE = 2;
    static const int MAX_SIZE = 1000000;
    static const int MIN_SIZE = 1;

private:
    int _rows;
    int _cols;
    int value;
    T** _matrix;
    void mem_alloc(int intRows, int intCols, int intValue);
    void mem_dealloc();
    void clone(GenericStorage2D<T>& objMatrix);
    void enforcedRange(int intArg, int intMin,  int intMax) const;

};

#include "GenericStorage2D.imp"
#endif // GENERICSTORAGE2D_H_INCLUDED
