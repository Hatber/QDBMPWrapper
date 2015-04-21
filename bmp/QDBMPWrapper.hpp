#ifndef __QDBMPWRAPPER__
#define __QDBMPWRAPPER__

extern "C" {
#include "qdbmp.h"
};

#include <string>

class QDBMPWrapper {
public:
    struct RGBColor {
        RGBColor(USHORT red, USHORT green, USHORT blue);
        bool operator == (const RGBColor& color);
        UCHAR r, g, b;
    };

    QDBMPWrapper(const std::string& fileName);
    QDBMPWrapper(UINT width, UINT height, USHORT depth = 24);

    virtual ~QDBMPWrapper();

    void Save(const std::string& fileName);

    UINT   GetWidth	();
    UINT   GetHeight();
    USHORT GetDepth	();

    void SetRGB(const RGBColor& color, UINT x, UINT y);
    void SetRGB(USHORT red, USHORT green, USHORT blue, UINT x, UINT y);

    RGBColor GetRGB(UINT x, UINT y);

    // ---- Sugar
    void Fill(const RGBColor& color);

private:
    BMP* bmp;
};

#endif // __QDBMPWRAPPER__
