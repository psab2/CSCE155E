
/**
 * Alter the passed string and set all of its
 * characters to the underscore
 * and properly null-terminate it
 */
void initializeBlankString(int length, char *string);

/**
 * print the contents of the string
 * character-by-character with spaces
 * between each one
 */
void printWithSpaces(char *string);

/**
 * Iterate over each character in the
 * second argument and "reveal" the
 * letter if it matches the guessed letter
 */
int revealGuessedLetter(const char *string, char *revealedLetters, char guess);

/**
 * Checks if the two strings are equal
 */
int checkGuess(const char *String1, char *String2);


//the following functions have been done for you.

/**
 * Sets the game up, checks for win condition,
 * prints relevant data
 */
void startGame(char *wordToGuess);

/**
 * Clears the unix terminal of previous input
 */
void clearScreen();

/**
 * Prints part of the horse based on the ratio between
 * the two numbers.
 */
void drawHorse(int guessedSoFar, int allowedGuesses);
