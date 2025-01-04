#include <stdlib.h>

#include "student.h"

/**
 * Student structure demonstration program
 */
int main(int argc, char **argv) {
  Student *me = createStudent("Prisha", "Sabherwal", 94130497, "06/07/2006");
  printStudent(me);
}

