/**
 * Prisha Sabherwal
 * 2024/11/07
 * protein translation program
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "protein_utils.h"
#include "file_utils.h"


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "error, enter enough arguments\n");
        exit(1);
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    //FILE *fileOut = fopen(outputFile, "w");

    FILE *fileIn = fopen(inputFile, "r");
    if (fileIn == NULL) {
      fprintf(stderr, "Error opening file\n");
      exit(1);
    }

    char *dnaSequence = getFileContents(inputFile);

    char *rnaSequence = replaceCharCopy(dnaSequence, 'T', 'U');

    removeChar(rnaSequence, '\n');

    char **codons = lengthSplit(rnaSequence, 3);
    char protein;

    fclose(fileIn);

    FILE *fileOut = fopen(outputFile, "w");
    if (fileOut == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    int length = 0;
    while(codons[length]!= NULL){
      length++;
    }
    for (int i=0; codons[i] != NULL; i++) {
      protein = rnaToProtein(codons[i]);
      if (protein == 'x') {
        break;
      }
      fprintf(fileOut, "%c", protein);
      free(codons[i]);
    }

    free(rnaSequence);
    free(dnaSequence);
    fclose(fileOut);
    return 0;
}
