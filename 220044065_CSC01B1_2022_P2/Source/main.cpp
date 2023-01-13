#include <iostream>
#include "Canvas2D.h"
using namespace std;

int main()
{
    Canvas2D objCanvas;
    int row1 = 250;
    int col1 = 250;
    int intRadius = 100;
    PGM_Pixel recColour = {0, 0, 0};

    Canvas2D objCopy(objCanvas);
    objCopy.drawshape(row1, col1, intRadius, recColour);
    cout << objCopy.toPGM() << endl;
    return 0;
}
