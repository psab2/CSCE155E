/**
 * Prisha Sabherwal
 * 2024/11/07
 * Definitions of function prototypes
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_utils.h"

char *getFileContents(const char *filePath) {
  FILE *file = fopen(filePath, "r");
    if (file == NULL) {
      return NULL;
    }
  int len;
  fseek(file, 0, SEEK_END);
  len = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *string = (char*) malloc(sizeof(char) * (len+1));
  fread(string, sizeof(char),len, file);
  string[len] = '\0';
  fclose(file);
  return string;
}

char **getFileLines(const char *filePath, int *numLines) {
  if (filePath == NULL || numLines==NULL) {
    return NULL;
  }
  FILE *file = fopen(filePath, "r");
    if (file == NULL) {
      return NULL;
    }
  char buffer[2000];
  int i = 0;
  while (fgets(buffer, sizeof(buffer), file)) {
    i++;
  }
  *numLines = i;
  char **linesArray = (char **) malloc(sizeof(char *) *i);

  rewind(file);
  i=0;
  while (fgets(buffer, sizeof(buffer), file)) {
    int n = strlen(buffer);
    if(buffer[n-1] == '\n'){
      buffer[n-1] = '\0';
    }
    linesArray[i] = (char *) malloc(sizeof(char) * (strlen(buffer)+1));
    strcpy(linesArray[i], buffer);

    i++;
  }
  fclose(file);
  return linesArray;
}



char * replaceCharCopy(const char *s, char oldChar, char newChar) {
  if(s==NULL) {
    return NULL;
  }
  char *copy = (char *) malloc(sizeof(char) * (strlen(s)+1));
  int a =strlen(s);
  for (int i=0; i<a; i++) {
    if (s[i]==oldChar) {
      copy[i] = newChar;
    }
    else {
      copy[i] = s[i];
    }
  }
  copy[strlen(s)] = '\0';
  return copy;
}

void removeChar(char *s, char c) {
  if(s==NULL) {
    return;
  }
  int j=0;
  for (int i=0; i<strlen(s); i++) {
    if (s[i]!=c) {
      s[j] = s[i];
      j++;
    }
  }
  s[j] = '\0';
  return;
}

char **lengthSplit(const char *s, int n) {
  if(s==NULL|| n<0) {
    return NULL;
  }
  int numOfStr = strlen(s)/n+(strlen(s)%n!=0);
  char **newStr = (char **) malloc (sizeof(char *) * numOfStr);
  for(int i=0; i<numOfStr; i++) {
    newStr[i] = (char *) malloc(sizeof(char) * (n+1));
  }
  for(int i=0; i<numOfStr; i++){
    strncpy(newStr[i],s+i*n, n);
    newStr[i][n] = '\0';
  }
  return newStr;
}

