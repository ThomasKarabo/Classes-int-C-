#include "PBMImage.h"
#include <cmath>
using namespace std;

class Image2D;

PBMImage::PBMImage()
{
    draw();
}

PBMImage::PBMImage(int intRows, int intCols): Image2D(intRows, intCols)
{
    draw();
}

PBMImage::PBMImage(const PBMImage& objOriginal)
{

}

string PBMImage::toPBM() const
{
    stringstream ssPBM;
    ssPBM << w_cols << ' ' <<endl
    << h_rows << "P2" <<endl
    << 255 <<endl;

    for(int h=0;h<h_rows; h++)
        for(int w=0;w<w_cols;w++)
            ssPBM << _pixels[h][w] << ' ';
        ssPBM<<endl;
    return ssPBM.str();


}
void PBMImage:: draw()
{
    int intCRow = _rows / 2;
    int intCCol = _cols / 2;
    double dblRadius = (3.0 / 10.0) * _rows;
    Image2D bgColor = {255, 0, 0};
    for(int h = 0; h < h_rows; h++)
    {
        for(int w = 0; w < w_cols; w++)
        {
            if(distance(r, c, intCRow, intCCol) <= dblRadius)
                _pixels[r][c] = bgColor;
            else
                _pixels[r][c] = {255, 255, 255};
        }
    }


}

void PBMImage::printImage()
{

}


PBMImage::~PBMImage()
{

}


