#include "Image2D.h"

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


string Image2D:: toString() const
{
    stringstream ssPPM;
    ssPPM << w_cols << ' ' << endl
    << h_rows << "P2" <<endl
    << 255 << endl;

    for(int h = 0; h<h_rows; h++){
        for(int w = 0; w<w_cols; w++){
            ssPPM << _pixels[h][w] <<' ';}
        ssPPM<<endl;}
    return ssPPM.str();

}

Image2D::Image2D() : Image2D(DEFAULT_ROWS, DEFAULT_COLS, DEFAULT_BG_COLOR)
{

}

Image2D::Image2D(int intRows, int intCols, int intBGColor)
{
    mem_alloc(intRows, intCols, intBGColor);
    draw();

}

Image2D::Image2D(const Image2D& objOriginal)
{
    mem_alloc(objOriginal.h_rows, objOriginal.w_cols, DEFAULT_BG_COLOR);
}

int Image2D::getRows() const
{
    return h_rows;
}
int Image2D::getCols() const
{
    return w_cols;
}
int Image2D::getColor() const
{
    return bgColor;
}
int Image2D::getPixel(int intRow, int intCol) const
{
    enforcedRange(intRow, 0, h_rows-1);
    enforcedRange(intRow, 0, w_cols-1);
    return _pixels[intRow][intCol];
}

void Image2D::setPixel(int intRow, int intCol, int intPixel)
{
    enforcedRange(intRow, 0, h_rows-1);
    enforcedRange(intRow, 0, w_cols-1);
    _pixels[intRow][intCol] = intPixel;
}

Image2D::~Image2D()
{
    mem_dealloc();
}

void Image2D:: mem_alloc(int intRows, int intCols, int intBGColor)
{
    h_rows = intRows;
    w_cols = intCols;
    bgColor = intBGColor;
    _pixels = new int*[h_rows];
    for(int h = 0; h<h_rows; h++){
        _pixels[h]= new int[w_cols];
        for(int w = 0; w < w_cols; w++){
            _pixels[h][w] = bgColor;}
    }
}

void Image2D::mem_dealloc()
{
    for(int h = 0; h<h_rows; h++)
        delete _pixels[h];
    delete _pixels;
}

void Image2D::enforcedRange(int intArg, int intMin, int intMax) const
{
    if(intArg < intMin || intArg > intMax){
        cerr << "Must be in [" << intMin << ", " << intMax << "]" <<endl;
       exit(ERROR_RANGE);
    }


}


