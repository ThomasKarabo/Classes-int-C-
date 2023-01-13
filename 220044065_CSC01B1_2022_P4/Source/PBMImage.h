#ifndef PBMIMAGE
#define PBMIMAGE
#include "Image2D.h"
#include <iostream>
#include <string>


//Derived Class
class PBMImage:public Image2D
{
public:
    PBMImage();
    PBMImage(int intRows, int intCols, int  intBGColor);
    PBMImage(const PBMImage& objOriginal);
    std::string toPBM() const;
    void draw();
    void printImage();
    ~PBMImage();

private:
    // double distance(int X1, int X2, int Y1, int Y2) const;
};

#endif // PBMIMAGE_H_INCLUDED
