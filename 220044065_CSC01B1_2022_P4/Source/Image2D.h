#ifndef IMAGE2D
#define IMAGE2D
//Parent Class
#include <iostream>
#include <string>

using namespace std;
enum ERROR_RANGE
{
    SUCCESS,
    ERROR_VALUE
};


class Image2D
{
    public:
        Image2D();
        Image2D(int intRows, int intCols, int  intBGColor);
        Image2D(const Image2D& objOriginal);


        //Accessor functions
        int getRows() const;
        int getCols() const;
        int getColor() const;
        int getPixel(int intRow, int intCol) const;

        //Mutator functions
        void setPixel(int intRow, int intCol, int intPixel);

        virtual std::string toString() const =0;

        virtual void draw();
        virtual void printImage();
        //Deconstructor
        ~Image2D();

        static const int DEFAULT_ROWS = 250;
        static const int DEFAULT_COLS = 250;
        static const int DEFAULT_MINSIZE = 1;
        static const int DEFAULT_MAXSIZE = 10000;
        static const int DEFAULT_BG_COLOR = 132;

    protected:
        int h_rows;
        int w_cols;
        int bgColor;
        void mem_alloc(int intRows, int intCols, int intBGColor);
        void mem_dealloc();
        void enforcedRange(int intArg, int intMin, int intMax) const;
        int** _pixels;



};



#endif // IMAGE2D_H_INCLUDED
