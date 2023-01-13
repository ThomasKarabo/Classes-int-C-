#include "CanvasCapper.h"

namespace CanvasSpace
{
    CanvasCapper();
    CanvasCapper(int intRows, int intCols, int intBGColour);
    void applyRangeRules(Canvas2D& objOriginal, int _max, int _min);
    string toPGM() const;





}
