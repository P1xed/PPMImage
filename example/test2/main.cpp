
#include <cmath>
#include <cstdint>

#include "PPMImage.h"

inline auto CrossProduction(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1,
                            uint8_t x2, uint8_t y2) -> double {
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

int main() {
    double vertexs[6]{32, 64, 192, 32, 64, 224};

    double area =
        std::abs(0.5 * (vertexs[2] - vertexs[0]) * (vertexs[5] - vertexs[1]) -
                 (vertexs[3] - vertexs[0]) * (vertexs[3] - vertexs[1]));

    PPMImage test(256, 256);

    for (int i = 0; i < 255; i++) {
        for (int k = 0; k < 255; k++) {

            auto cross1 =
                CrossProduction(vertexs[0], vertexs[1], vertexs[2], vertexs[3], i, k);
            auto cross2 =
                CrossProduction(vertexs[2], vertexs[3], vertexs[4], vertexs[5], i, k);
            auto cross3 =
                CrossProduction(vertexs[4], vertexs[5], vertexs[0], vertexs[1], i, k);

            if (cross1 > 0 && cross2 > 0 && cross3 > 0 ||
                cross1 < 0 && cross2 < 0 && cross3 < 0) {

                auto area1 =
                    std::abs(0.5f * CrossProduction(i, k, vertexs[2], vertexs[3],
                                                    vertexs[4], vertexs[5]));

                auto area2 =
                    std::abs(0.5f * CrossProduction(i, k, vertexs[4], vertexs[5],
                                                    vertexs[0], vertexs[1]));

                auto area3 =
                    std::abs(0.5f * CrossProduction(i, k, vertexs[0], vertexs[1],
                                                    vertexs[2], vertexs[3]));

                auto R = 255 * area1 / area;
                auto G = 255 * area2 / area;
                auto B = 255 * area3 / area;
                test.WritePixel(i, k, R, G, B);
                } else {
                    test.WritePixel(i, k, 0, 0, 0);
                }
        }
    }

    test.Export("test2.ppm");

    return 0;
}
