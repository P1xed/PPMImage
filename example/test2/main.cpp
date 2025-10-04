
#include "PPMImage.h"

int main() {
    float vertexs[6]{
        64, 64,
        128, 32,
        32, 128
    };

    double area = 0.5 * (vertexs[2]-vertexs[0]) * (vertexs[5]-vertexs[1]) - (vertexs[3]-vertexs[0])* (vertexs[3]-vertexs[1]);

    PPMImage test(256, 256);

    for (int i = 0 ; i < 255; i++) {
        for (int k = 0 ; k < 255; k++) {

            if (

                )

            test.WritePixel(i,k,0,0,0);
        }
    }

    test.Export("test2.ppm");

    return 0;
}
