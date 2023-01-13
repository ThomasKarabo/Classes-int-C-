#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <ostream>
enum ERROR_RANGE
{
    SUCCESS,
    ERROR_VALUE
};


class Matrix2D
{
    public:
        Matrix2D();
        Matrix2D(int intRows, int intCols,int intValue);
        Matrix2D(const Matrix2D& objOriginal);

        int getRows() const;
        int getCols() const;
        int getValue(int intRow, int intCol) const;

        const Matrix2D& operator=( const Matrix2D& objOriginal);//Assigment operator
        Matrix2D& operator()(int intRow, int intCol);//() operator

        friend std::ostream& operator<<(std::ostream& objLHS, const Matrix2D& objOriginal);//output stream operator

        Matrix2D operator++();
        Matrix2D operator++(int);

        void setValue (int intRow, int intCol, int intVal);

        ~Matrix2D();

        static const int DEFAULT_SIZE = 10;
        static const int DEFAULT_VALUE = 0;
        static const int DEFAULT_MINSIZE = 1;
        static const int DEFAULT_MAXSIZE = 100;

    private:
        int _rows;
        int _cols;
        int value;
        int* _matrix;
        void mem_alloc(int intRows, int intCols,int intValue);
        void mem_dealloc();
        void clone(const Matrix2D& objOriginal);
        void enforcedRange(int intArg, int intMin, int intMax) const;
};


#endif // MATRIX2D_H
