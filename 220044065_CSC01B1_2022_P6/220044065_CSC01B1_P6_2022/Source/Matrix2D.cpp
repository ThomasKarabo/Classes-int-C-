#include "Matrix2D.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <stdlib.h>

using namespace std;

Matrix2D::Matrix2D():Matrix2D(DEFAULT_SIZE, DEFAULT_SIZE, DEFAULT_VALUE){}


Matrix2D::Matrix2D(int intRows, int intCols,int intValue)
{
    mem_alloc(intRows, intCols, intValue);
}


Matrix2D::Matrix2D(const Matrix2D& objOriginal)
{
    mem_alloc(objOriginal._rows,objOriginal._cols, DEFAULT_VALUE);
    *this = objOriginal;
}

int Matrix2D::getRows() const
{
    return _rows;
}

int Matrix2D::getCols() const
{
    return _cols;
}


int Matrix2D::getValue(int intRow, int intCol) const
{
    enforcedRange(intRow, 0, _rows -1);
    enforcedRange(intCol, 0, _cols - 1);
    return _matrix[intRow][intCol];
}


const Matrix2D& Matrix2D::operator=( const Matrix2D& objRHS)
{
    if(this != objRHS)
    if(_rows != objRHS._rows || _cols != objRHS._cols){
        mem_dealloc();
        mem_alloc(objRHS._rows, objRHS._cols);
    }clone(objRHS);

}


Matrix2D& Matrix2D::operator()(int intRow, int intCol)
{
     enforceRange(intRow, 0, _rows - 1);
     enforceRange(intCol, 0, _cols - 1);
     return _matrix[intRow][intCol];
}


ostream& operator<<(ostream& objLHS, const Matrix2D& objRHS)
{
    for(int r = 0; r < objRHS._rows; r++)
        for(int c = 0; c < objRHS._cols; c++){
        objLHS  << objRHS._matrix[r][c] << ' ';
    }objLHS <<endl;
    return objLHS;
}


void Matrix2D::mem_alloc(int intRows, int intCols,int intValue)
{
    _rows = intRows;
    _cols = intCols;
    value = intValue;

    _matrix = new Matrix2D[_rows];
    for(int r = 0; r < _rows; r++){
       _matrix[r] = new Matrix2D[_cols];
    }


}


 void Matrix2D::clone(const Matrix2D& objOriginal)
 {
     for(int r = 0; r <_rows; r++)
        for(int c = 0; c < _cols; c++)
            (*this)[r][c] = objOriginal._matrix[r][c];
 }


void Matrix2D::mem_dealloc()
{
    assert(_matrix != 0);
    for(int r = 0; r < _rows; r++)
        delete[] *_matrix[r];
    delete[] _matrix;
}

void Matrix2D::enforcedRange(int intArg, int intMin, int intMax) const
{
    if(intArg < intMin || intArg > intMax)
        cerr << intArg <<"Should be in range [" << intMin << ": " << intMax << "]" <<endl;
        exit(ERROR_VALUE);
}


Matrix2D::~Matrix2D()
{
    mem_dealloc();
}

