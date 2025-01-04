/**
 * Prisha Sabherwal
 * 2024/11/07
 * A collection of function prototypes
 */

/**
 * given a file path/name as a string opens the
 * file and returns its entire contents as a single string
 */
char *getFileContents(const char *filePath);

/**
 * given a file path/name as a string opens the
 * file and returns the contents of the file as an
 * array of strings. Each element in the array
 * should correspond to a line in the file
 */
char **getFileLines(const char *filePath, int *numLines);

/**
 * takes a string and creates a new copy of it
 * but with instances of a given character replaced
 * with a different character.
 */
char * replaceCharCopy(const char *s, char oldChar, char newChar);


/**
 * takes a string and removes all
 * instances of a certain character from it.
 */
void removeChar(char *s, char c);

/**
 * takes a string and splits it up
 * to an array of strings. The split
 * will be length-based
 */
char **lengthSplit(const char *s, int n);

//void printProtein(char **codons, FILE *fileOut);
