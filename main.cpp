#include <iostream>

#include "bmp/QDBMPWrapper.hpp"

using namespace std;

const string exampleImageName = "Examples/Tux.bmp";

void negative(const string& sourceImage);

int main() {
    negative(exampleImageName);

    return 0;
}

void negative(const string& sourceImage) {
    QDBMPWrapper negative(sourceImage);

    UINT width  = negative.GetWidth();
    UINT height = negative.GetHeight();

    for (UINT x = 0 ; x < width ; ++x) {
        for (UINT y = 0 ; y < height ; ++y) {
            QDBMPWrapper::RGBColor pixel = negative.GetRGB(x, y);
            negative.SetRGB(255 - pixel.r, 255 - pixel.g, 255 - pixel.b, x, y);
        }
    }

    negative.Save("Negative.bmp");
}
