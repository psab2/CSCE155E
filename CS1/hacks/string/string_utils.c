/**
 * Prisha Sabherwal
 * 2024/10/31
 * definition of function prototypes
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "string_utils.h"

void replaceChar(char *s, char oldChar, char newChar) {
  if(s==NULL) {
    return;
  }
  for (int i=0; i<strlen(s); i++) {
    if (s[i]==oldChar) {
      s[i] = newChar;
    }
  }
  return;
}

char * replaceCharCopy(const char *s, char oldChar, char newChar) {
  if(s==NULL) {
    return NULL;
  }
  char *copy = (char *) malloc(sizeof(char) * (strlen(s)+1));
  for (int i=0; i<strlen(s); i++) {
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

char * removeCharCopy(const char *s, char c) {
  if(s==NULL) {
    return NULL;
  }
  int j=0;
  char *copy = (char *) malloc(sizeof(char) * (strlen(s)+1));
  for (int i=0; i<strlen(s); i++) {
    if (s[i]!=c) {
      copy[j] = s[i];
      j++;
    }
  }
  copy[j] = '\0';
  return copy;
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
