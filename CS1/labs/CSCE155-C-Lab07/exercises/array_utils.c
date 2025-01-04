#include <stdlib.h>
#include <stdio.h>

#include "array_utils.h"

void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}

void printTable(int **table, int n, int m) {
  if(table == NULL) {
    printf("[null]\n");
    return;
  }
  for(int i=0; i<n; i++) {
    printArray(table[i], m);
  }
  return;
}

int * generateRandomArray(int size) {
  if(size < 0) {
    return NULL;
  }
  //int randomArr[size];
  int *randomArr = (int *) malloc(sizeof(int)*size);
  for(int i=0; i<size; i++) {
    randomArr[i] = rand() % 100;
  }
  return randomArr;
}

int getSum(const int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
  int total = 0;
  for(int i=0; i<size; i++) {
    total += arr[i];
    //arr[i] = 0;
  }
  return total;
}

void freeTable(int **table, int n) {
  if(table == NULL) {
    return;
  }
  for(int i=0; i<n; i++) {
    free(table[i]);
  }
  free(table);
}

double getMean(const int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
  double mean = 0;
  for(int i=0; i<size; i++) {
    mean += arr[i];
  }
  mean /=size;
  return mean;
}

int getMin(const int *arr, int size) {
  int min = arr[0];
  for(int i=1; i<size; i++){
      min = min < arr[i] ? min : arr[i];
  }
  return min;
}

int getIndexOfMin(const int *arr, int size) {
  int min = arr[0];
  int indexMin = 0;
  for(int i=1; i<size; i++){
    if (arr[i]<min) {
      min = arr[i];
      indexMin = i;
    }
  }
  return indexMin;
}

int getMax(const int *arr, int size) {
  int max = arr[0];
  for(int i=1; i<size; i++){
      max = max > arr[i] ? max : arr[i];
  }
  return max;
}

int getIndexOfMax(const int *arr, int size) {
  int max = arr[0];
  int indexMax = 0;
  for(int i=1; i<size; i++){
    if (arr[i]>max) {
      max = arr[i];
      indexMax = i;
    }
  }
  return indexMax;
}

int * filterThreshold(const int *arr, int size, int threshold, int *resultSize) {
  int newSize = 0;
  for(int i=0; i<size; i++){
    if (arr[i]>=threshold){
      newSize++;
    }
  }
  int *newArr = (int *) malloc(sizeof(int) * size);
  int j = 0;
  for(int i=0; i<size; i++){
    if (arr[i]>=threshold){
      newArr[j] = arr[i];
      j++;
    }
  }
  *resultSize = newSize;
  return newArr;
}

int **createMultiplicationTable(int n, int m) {
  int **table = (int **) malloc(sizeof(int *) * n);
  for(int i=0; i<n; i++) {
    table[i] = (int *) malloc(sizeof(int) * m);
  }
  for(int i=0; i<n; i++){
    for(int x=0; x<m; x++)
    table[i][x]=(1+i)*(1+x);
  }
  return table;
}
