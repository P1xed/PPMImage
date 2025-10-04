#include "PPMImage.h"

#include <fstream>
#include <iostream>
#include <sstream>

PPMImage::PPMImage(int width, int height)
    : width(width), height(height) {
    buffer.resize(width * height * 3, {0, 0, 0});
}

void PPMImage::WritePixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    this->buffer[x + y * width] = {r, g, b};
}

void PPMImage::Export(const std::string &name) const {
    std::ofstream file(name, std::ios::binary);
    file << "P3\n" << width << " " << height << "\n255\n";

    std::cout << "Export starts\n";

    for (int i = 0; i < width * height; i++) {
        std::cout << "Writing" << i+1 << ": " << std::to_string(buffer[i].r) << " " << std::to_string(buffer[i].g) << " "
                << std::to_string(buffer[i].b) << "\n";
        file << std::to_string(buffer[i].r) << " " << std::to_string(buffer[i].g) << " " << std::to_string(buffer[i].b)
                << "\n";
    }
    std::cout << "Exported file successfully.\n";
}

