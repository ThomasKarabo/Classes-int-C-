#ifndef MATRIX2D_H_INCLUDED
#define MATRIX2D_H_INCLUDED

#include <iostream>
#include <string>

enum ERROR_CODE
{
    SUCCESS,
    ERROR_VALUE
};

class Matrix2D
{
public:
//Constructor
    Matrix2D();
    Matrix2D(int intRows, int intCols,int intValue);
    Matrix2D(const Matrix2D& objOriginal);
//Accessors
    int getRows() const;
    int getCols() const;
    int getValue() const;
 //Mutators
    void setValue(int intRow, int intCol, int intValue);

    std::string toString() const;
    void print();
    void drawMatrix();
//Destructor
    ~Matrix2D();

    static const int DEFAULT_ROWS=10;
    static const int DEFAULT_COLS=10;
    static const int DEFAULT_VALUE = 0;


private:
    int _rows;
    int _cols;
    int value;
    void mem_alloc(int intRows, int intCols,int intValue);
    void mem_dealloc();
    void enforceRange(int intArg, int intMin, int intMax);
    int** _matrix;
};

#endif // MATRIX2D_H_INCLUDED
