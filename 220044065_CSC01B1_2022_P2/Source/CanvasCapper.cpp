#include "CanvasCapper.h"

using namespace std;

namespace CanvasSpace
{
    CanvasCapper();
    CanvasCapper(int intRows, int intCols, int recDefault);
    void applyRangeRules(Canvas2D& objOriginal, int _max, int _min);
    std::string toPGM() const

     void draw_circle(int intR, int intC, int intRadius,PGM_Pixel recPixel)

     void draw_rec(int intX, int intY,int intWidth, int intHeight, PGM_Pixel recDefault)
}
