#ifndef CANVASCAPPER
#define CANVASCAPPER

#include <iostream>
#include <string>
#include "Canvas2D.h"

namespace CanvasSpace{


enum ERROR_CODE{
    SUCCESS,
    ERROR_RANGE = -1
};

class CanvasCapper
{
public:
    CanvasCapper();
    CanvasCapper(int intRows, int intCols, int intBGColour);
    void applyRangeRules(Canvas2D& objOriginal, int _max, int _min);
    std::string toPGM() const;


    static const int DEFAULT_ROWS = 250;
    static const int DEFAULT_COLS = 250;
    static const int DEFAULT_BG_COL= 132;
    static const int MAX = 255;
    static const int MIN = 0;

private:
    int h_rows;
    int w_cols;
};

}

#endif // CANVASCAPPER
