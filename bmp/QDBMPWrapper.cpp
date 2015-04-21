#include "QDBMPWrapper.hpp"

QDBMPWrapper::RGBColor::RGBColor(USHORT red, USHORT green, USHORT blue) : r(red), g(green), b(blue) { }
bool QDBMPWrapper::RGBColor::operator==(const RGBColor &color) {
    return (r == color.r) && (g == color.g) && (b == color.b);
}

QDBMPWrapper::QDBMPWrapper(const std::string& fileName){ bmp = BMP_ReadFile(fileName.c_str()); }
QDBMPWrapper::QDBMPWrapper(UINT width, UINT height, USHORT depth) { bmp = BMP_Create(width, height, depth); }

QDBMPWrapper::~QDBMPWrapper() { BMP_Free(bmp); }

#include <iostream>

void QDBMPWrapper::Save(const std::string& fileName) { BMP_WriteFile(bmp, fileName.c_str()); std::cout << BMP_GetError() << std::endl; }

UINT QDBMPWrapper::GetWidth()   { return BMP_GetWidth(bmp); }
UINT QDBMPWrapper::GetHeight()  { return BMP_GetHeight(bmp); }
USHORT QDBMPWrapper::GetDepth() { return BMP_GetDepth(bmp); }

void QDBMPWrapper::SetRGB(const RGBColor& color, UINT x, UINT y){ SetRGB(color.r, color.g, color.b, x, y); }
void QDBMPWrapper::SetRGB(USHORT red, USHORT green, USHORT blue, UINT x, UINT y) {
    BMP_SetPixelRGB(bmp, x, y, red, green, blue);
}

QDBMPWrapper::RGBColor QDBMPWrapper::GetRGB(UINT x, UINT y) {
    RGBColor color(0, 0, 0);
    BMP_GetPixelRGB(bmp, x, y, &color.r, &color.g, &color.b);

    return color;
}

void QDBMPWrapper::Fill(RGBColor const &color) {
    for(UINT i = 0; i < GetWidth(); i++) {
        for(UINT j = 0; j < GetHeight(); j++) {
            SetRGB(color, i, j);
        }
    }
}
