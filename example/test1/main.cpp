
#include "PPMImage.h"

int main() {
    PPMImage test(255,255);
    for (int i = 0 ; i < 255; i++) {
        for (int k = 0 ; k < 255; k++) {
            test.WritePixel(i,k,i,k,0);
        }
    }
    test.Export("test1.ppm");
    return 0;
}