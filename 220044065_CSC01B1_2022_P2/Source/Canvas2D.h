#ifndef CANVAS2D_H_INCLUDED
#define CANVAS2D_H_INCLUDED

#include <iostream>
#include <sstream>
#include <cmath>
#include "CanvasCapper.h"

class CanvasCapper;

struct PGM_Pixel
{
    int red;
    int blue;
    int green;
};

class Canvas2D
{
public:
    //constuctor
    Canvas2D();
    //Constructor with args
    Canvas2D(int intRows, int intCols, PGM_Pixel recDefault);
   //copy constructor
    Canvas2D(const Canvas2D& objOriginal);
    //Returns a P3 PGM Image
    std::string toPGM() const;
    //Accessor member functions
    int getRows() const;
    int getCols() const;
    PGM_Pixel get_pixel(int intRow, int intCol) const;

    void applyRangeRules(Canvas2D& objOriginal, int _max, int _min);

        // This will draw the big circle
     void draw_circle(int intR, int intC, int intRadius,PGM_Pixel recPixel);

     void draw_rec(int intX, int intY,int intWidth, int intHeight, PGM_Pixel recDefault);
     //Mutator member function
     void setPixel(int intRow, int intCol, PGM_Pixel recPixel);


    static const int DEFAULT_ROWS = 250;
    static const int DEFAULT_COLS = 250;
    static const int MAX_SIZE=1000;
    static const int DEFAULT_BGCOL =0;


    ~Canvas2D();

private:
    //Image height
    int h_rows;
    //Image width
    int w_cols;
    void mem_alloc(int intRows, int intCols, PGM_Pixel recDefault);
    void mem_dealloc();
    void mem_clone(const Canvas2D& objOriginal);
    double distance(double dblRow, double row1, double dblCol, double col1) const;
    void enforceRange(int intArg, int intMin, int intMax) const;

    bool isInRange(int intRow, int intCol) const;
    int _x;
    int _y;
    int _width;
    int _height;
    int _bgcolor;
    //Let's create a 2D array for the image
    PGM_Pixel** _pixels;
};


#endif // CANVAS2D_H_INCLUDED
