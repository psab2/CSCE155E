/**
 * Prisha Sabherwal
 * 2024/09/27
 * program that reads in three points, (xa, ya), (xb, yb), and (xc, yc) and
 * computes the distance between them all and then outputs the closest two points.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 7) {
        printf("ERROR: Xa, Xb, Ya, Yb\n");
        exit(1);
    }

    double xa = atof(argv[1]);
    double ya = atof(argv[2]);
    double xb = atof(argv[3]);
    double yb = atof(argv[4]);
    double xc = atof(argv[5]);
    double yc = atof(argv[6]);

    double distanceAB = sqrt(pow(xb-xa,2)+pow(yb-ya,2));
    double distanceAC = sqrt(pow(xc-xa,2)+pow(yc-ya,2));
    double distanceBC = sqrt(pow(xc-xb,2)+pow(yc-yb,2));

    if (distanceAB<distanceAC && distanceAB<distanceBC) {
        printf("Closest two points: ab");
    }
    else if (distanceAC<distanceAB && distanceAC<distanceBC) {
        printf("Closest two points: ac");
    }
    else if (distanceBC<distanceAB && distanceBC<distanceAC) {
        printf("Closest two points: bc");
    }


    printf("Distance ab: %.6f\n", distanceAB);
    printf("Distance ac: %.6f\n", distanceAC);
    printf("Distance bc: %.6f\n", distanceBC);

    return 0;
}
