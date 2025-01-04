/**
 * Prisha Sabherwal
 * 2024/10/17
 * definitions of all the function prototypes
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "array_utils.h"

int contains(const int *arr, int size, int x) {
  if(arr == NULL) {
    printf("[null]\n");
    return 1;
  }

  for(int i=0; i<size; i++) {
    if(arr[i] == x) {
      return true;
    }
  }
  return false;

  if(size < 0) {
    return 2;
  }
}

int containsWithin(const int *arr, int size, int x, int i, int j) {
  if(arr == NULL) {
    printf("[null]\n");
    return 1;
  }

  for(int i=0; i<=j; i++) {
    if(arr[i] == x){
      return true;
    }
  }
  return false;
}

int * paddedCopy(const int *arr, int oldSize, int newSize) {
  if(arr == NULL) {
    printf("[null]\n");
    return NULL;
  }
  if(oldSize < 0) {
    printf("[null]\n");
    return NULL;
  }
  if(newSize<0) {
    printf("[null]\n");
    return NULL;
  }

  int *newArr = (int *) malloc(sizeof(int) * newSize);

  int min = oldSize < newSize ? oldSize : newSize;
  for(int i=0; i<min; i++){
    newArr[i]=arr[i];
  }

  if(oldSize<newSize) {
    for(int i=oldSize; i<newSize; i++){
      newArr[i]=0;
    }
  }
  return newArr;
}

void reverse(int *arr, int size) {
  int reversedArr[size];
  for(int i=0; i<size; i++) {
    reversedArr[i] = arr[size-i-1];
  }
  for(int i=0; i<size; i++) {
    arr[i]=reversedArr[i];
  }
}

int * reverseCopy(const int *arr, int size) {
  if(arr == NULL) {
    printf("[null]\n");
    return NULL;
  }

  int *newArr = (int *) malloc(sizeof(int) * size);

  for(int i=0; i<size; i++) {
    newArr[i] = arr[size-i-1];
  }
  for(int i=0; i<size; i++) {
  }
  return newArr;
}

