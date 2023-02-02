#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char* OutputFileName = malloc(strlen(inputName)+8*sizeof(*OutputFileName));
  strcpy(OutputFileName, inputName);
  strcat(OutputFileName, ".counts");
  return OutputFileName;
}
