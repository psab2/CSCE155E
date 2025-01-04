
#include "colorUtils.h"
#include <math.h>

double rgbIntToFloat(int c) {
  return (c / 255.0);
}

int max(int x, int y, int z) {
  int m = x > y ? x : y;
  m = m > z ? m : z;
  return m;
}

int toGrayScaleAverage(int r, int g, int b) {
  //TODO: test this, it may be wrong!
  return round((r + g + b) / 3.0);
}

int min(int x, int y, int z) {
  int m = x < y ? x : y;
  m = m < z ? m : z;
  return m;
}

int toGrayScaleLightness(int r, int g, int b) {
  int grayScaleLight = round((max(r,g,b)+min(r,g,b))/2)+1;
    if (grayScaleLight > 255) {
      return (255);
  }
  return(grayScaleLight);
}

int toGrayScaleLuminosity(int r, int g, int b) {
  return round(0.21*r+0.72*g+0.07*b);
}

int toSepiaRed(int r, int g, int b) {
  double sepiaR = round(0.393*r+0.769*g+0.189*b);
  if (sepiaR > 255) {
      return (255);
  }
  return (sepiaR);
}

int toSepiaGreen(int r, int g, int b) {
  double sepiaG = round(0.349*r+0.686*g+0.168*b);
  if (sepiaG > 255) {
      return (255);
  }
  return (sepiaG);
}

int toSepiaBlue(int r, int g, int b) {
  double sepiaB = round(0.272*r+0.534*g+0.131*b);
  if (sepiaB > 255) {
      return (255);
  }
  return (sepiaB);
}
