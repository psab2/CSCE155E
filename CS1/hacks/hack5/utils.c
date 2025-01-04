#include "utils.h"
#include <math.h>

double degreesToRadians(double degree) {
    return degree * M_PI / 180.0;
}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude){
        originLatitude = degreesToRadians(originLatitude);
        originLongitude = degreesToRadians(originLongitude);
        destinationLatitude = degreesToRadians(destinationLatitude);
        destinationLongitude = degreesToRadians(destinationLongitude);
        double diffrenceLongitude = destinationLongitude - originLongitude;
        return acos(sin(originLatitude) * sin(destinationLatitude) + cos(originLatitude) * cos(destinationLatitude) * cos(diffrenceLongitude)) * 6371.0;
}


double lorentzTimeDilation(double t, double percentC) {
    return (t/(sqrt(1 - (pow(percentC,2)))));
}
