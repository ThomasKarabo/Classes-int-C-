#ifndef PGMIMAGE
#define PGMIMAGE
#include "Image2D.h"
#include <iostream>
#include <string>


//Derived Class
class PGMImage:public Image2D
{
public:
    PGMImage();
    PGMImage(int intRows, int intCols, int  intBGColor);
    PGMImage(const PGMImage& objOrignal);
    std::string toPGM() const;
    void draw();
    void printImage();

    ~PGMImage();

private:

};



#endif // PGMIMAGE_H_INCLUDED
