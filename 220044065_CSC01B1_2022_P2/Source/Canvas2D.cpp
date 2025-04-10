#include "Canvas2D.h"
using namespace std;

     string Canvas2D::toPGM() const{
        stringstream ssPGM;
        ssPGM << "P2" << endl
              << h_rows << ' ' << w_cols << endl
              << 255 << endl;
        for(int h = 0; h < h_rows; h++){
            for(int w = 0; w < w_cols; w++){
                ssPGM << PGM_Pixel[h][w] <<' ';
            }
            ssPGM << endl;
        }
        return ssPGM.str();
    }
    //Constructor chaining
    Canvas2D::Canvas2D(): Canvas2D(DEFAULT_ROWS, DEFAULT_COLS,DEFAULT_BGCOL})
    {
    }

    Canvas2D:: Canvas2D(int intRows, int intCols, PGM_Pixel recDefault)
    {
        mem_alloc(intRows, intCols, recDefault);
    }

    Canvas2D::Canvas2D(const Canvas2D& objOriginal)
    {
        mem_alloc(objOriginal.h_rows, objOriginal.w_cols, DEFAULT_BGCOL);

        for(int h=0; h<h_rows; h++)
            for(int w=0; w<w_cols; w++)
                _pixels[h][w] = objOriginal._pixels[h][w];
    }
    void Canvas2D::draw_circle(int intCR, int intCC, int intRadius, PGM_Pixel recPixel){
        for(int h = 0; h < h_rows; h++)
            for(int w = 0; w < w_cols; w++)
                if(distance(h, intCR, w, intCC) <= intRadius)
                    _pixels[h][w] = recPixel;

    }
    void Canvas2D::draw_rec(int intX, int intY,int intWidth, int intHeight, PGM_Pixel recDefault){
        for(int h = 0; h < h_rows; h++)
            for(int w = 0; w < w_cols; w++)
                if(isInRange(intX, intY))
                     _pixels[h][w] = recDefault;


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

     void Canvas2D::setPixel(int intRow, int intCol, PGM_Pixel recPixel)
     {
        enforceRange(intRow, 0, MAX_SIZE);
        enforceRange(intCol, 0, MAX_SIZE);
        _pixels[intRow][intCol]=recPixel;
     }

    Canvas2D::~Canvas2D()
    {
        for(int h=0; h<h_rows; h++)
        {
            delete [] _pixels[h];
                delete[] _pixels;
        }
    }

    double Canvas2D::distance(double dblRow, double row1, double dblCol, double col1) const
    {
        return sqrt(pow(dblRow-row1,2) + pow(dblCol-col1,2));
    }

     void Canvas2D::enforceRange(int intArg, int intMin, int intMax) const
     {
        if(intArg < intMin || intArg > intMax){
            cerr << "Invalid argument: " << intArg << endl;
            //exit(-1);
        }
    }

    void Canvas2D::mem_alloc(int intRows, int intCols, PGM_Pixel recDefault)
    {
        h_rows = intRows;
        w_cols = intCols;
        _pixels = new PGM_Pixel*[h_rows];
        for(int h = 0; h < h_rows; h++){
            _pixels[h] = new PGM_Pixel[w_cols];
            for(int w = 0; w < w_cols; w++){
                _pixels[h][w] = recDefault;
            }
        }

    }


