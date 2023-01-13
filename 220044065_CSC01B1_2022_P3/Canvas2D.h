#ifndef CANVAS2D
#define CANVAS2D

#include <iostream>
#include "CanvasCapper.h"

using namespace std;
namespace CanvasSpace{


enum ERROR_CODE{
    SUCCESS,
    ERROR_RANGE = -1
};

class Canvas2D
{
public:
    Canvas2D();
    Canvas2D(int intRows, int intCols, int intBGColour);
    string toPGM() const;
    void applyRangeRules(Canvas2D& objOriginal, int _max, int _min);
    void drawCircle();
    void drawRectangle();

    RGBPixel getPixel(int intRow, int intCol) const;
    int getRows() const;
    int getCols() const;


    ~Canvas2D();

    static const int DEFAULT_ROWS = 250;
    static const int DEFAULT_COLS = 250;
    static const int DEFAULT_BG_COL= 132;
    static const int MAX = 255;
    static const int MIN = 0;

private:
    void mem_alloc();
    void mem_dealloc();
    int h_rows;
    int w_cols;

    RGBPixel** _pixels;
};

}



#endif // CANVAS2D
