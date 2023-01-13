#include "Matrix2D.h"
#include <sstream>
#include <cassert>
#include <iostream>

using namespace std;



Matrix2D::Matrix2D():Matrix2D(DEFAULT_ROWS, DEFAULT_COLS, DEFAULT_VALUE){}

Matrix2D::Matrix2D(int intRows, int intCols,int intValue)
{
    mem_alloc(intRows, intCols, intValue);
}

Matrix2D::Matrix2D(const Matrix2D& objOriginal)
{
    mem_alloc(objOriginal._rows, objOriginal._cols, DEFAULT_VALUE);
}

int Matrix2D::getRows() const
{
    return _rows;
}
int Matrix2D::getCols() const
{
    return _cols;
}

int Matrix2D::getValue() const
{
    return value;
}


void Matrix2D::setValue(int intRow, int intCol, int intVal)
{
    enforceRange(intRow, 0, _rows - 1);
    enforceRange(intCol, 0, _cols - 1);
    _matrix[intRow][intCol] = intVal;
}

string Matrix2D::toString() const
{
    stringstream toSTR;

    for(int r = 0; r<_rows; r++){
        for(int c = 0; c<_cols; c++){
            toSTR<< _matrix[r][c]<< ' ';
    }
    }

    return toSTR.str();
}
void Matrix2D::drawMatrix()
{
    for(int r  = 0 ; r < _rows; r++){
        for(int c = 0; c < _cols; c++){
             _matrix[r][c] = value;
        }
    }

}

void Matrix2D::print()
{
    for(int r  = 0 ; r < _rows; r++){
        for(int c = 0; c < _cols; c++){
             cout << _matrix[r][c];
        }
    }
}

Matrix2D::~Matrix2D()
{
    mem_dealloc();
}

void Matrix2D::mem_alloc(int intRows, int intCols, int intValue)
{
    _rows = intRows;
    _cols = intCols;
    value = intValue;

    _matrix = new int*[_rows];
    for(int r = 0; r < _rows; r++){
        _matrix[r] = new int [_cols];
        for(int c = 0; c < _cols; c++){
            _matrix[r][c] = value;
        }
    }
}
void Matrix2D::mem_dealloc()
{
    for(int r = 0; r < _rows; r++)
    {
        delete[] _matrix[r];
        for(int c= 0; c<_cols; c++){
            delete[] _matrix[c];
        }
    }
    delete[] _matrix;
}

void enforceRange(int intArg, int intMin, int intMax)
{
    if(intArg < intMin && intArg > intMax)
    {
        cerr << "Should be within [" << intMin <<" : "<< intMax  <<"]" <<endl;
        //exit(ERROR_VALUE);
    }
}
