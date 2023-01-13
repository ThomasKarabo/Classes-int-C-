#include "Canvas2D.h"

namespace CanvasSpace
{
    Canvas2D::Canvas2D():Canvas2D(DEFAULT_ROWS,DEFAULT_COLS,DEFAULT_BG_COL)
    {

    }

    Canvas2D::Canvas2D(int intRows, int intCols, int intBGColour);

    string Canvas2D::toPGM() const
    {
        stringstream ssPPM;
        ssPPm << "P2" << endl
        << w_cols << ' ' << h_rows << endl
        << 255 << endl;

        for(int h=0; h<h_rows; h++)
            for(int w=0;w<w_cols;w++)
            ssPPM << _pixels[h][w] << ' ';
        return ssPPM.str();

    }

    void Canvas2D::applyRangeRules(Canvas2D& objOriginal, int _max, int _min)
    {

    }

    void Canvas2D::drawCircle(int CRows; int CCols; int intRadius; int intPixel)
    {
         for(int h=0; h<h_rows; h++)
            for(int w=0;w<w_cols;w++)
                if(distance(h, CRows,w,CCols) <=intRadius)
                    _pixels[h][w]=intPixel;
    }

    void Canvas2D::drawRectangle(int intRow, int intCol, int intHeight, int intLength, int
intPixe)
    {
        for(int h=0; h < h_rows; h++)
            for(int w=0; w < w_cols; w++)
                if(h>=intRow && h<=(intRow + intHeight))
                    if(c>=intCol && c<=(intCol + intLength))
                        _pixels[h][w]=intPixel;
    }

    RGBPixel Canvas2D::getPixel(int intRow, int intCol) const
    {

    }

    int Canvas2D::getRows() const
    {
        return h_rows;
    }

    int Canvas2D::getCols() const
    {
        return w_cols;
    }
    PGM_Pixel Canvas2D::get_pixel(int intRow, int intCol) const
    {
       enforceRange(intRow, 0, MAX_SIZE);
       enforceRange(intCol, 0, MAX_SIZE);
       return _pixels[intRow][intCol];
    }




}
