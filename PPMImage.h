#pragma once

#include <string>
#include <vector>

class PPMImage {
public:
    PPMImage(int width, int height);

    ~PPMImage() = default;

    void WritePixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);

    void Export(const std::string &name) const;

private:

public:
    int width, height;
private:
    struct Color {
        uint8_t r, g, b;
    };


    std::vector<Color> buffer;
};
