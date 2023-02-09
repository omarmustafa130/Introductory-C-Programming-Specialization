#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t* counts = malloc(sizeof(*counts));
  counts->arrayLength = 0;
  counts->countUnknownNames = 0;
  counts->countArray = NULL;
  return counts;
}
void addCount(counts_t * c, const char * name) {
  
  if (name == NULL)
  {
    c->countUnknownNames = c->countUnknownNames + 1;
  }
  else
  {
    int nameFound = 0;
    for (int i = 0; i < c->arrayLength; i++)
    {
      if((strcmp(c->countArray[i]->n, name)) == 0){
        c->countArray[i]->seenTimes = c->countArray[i]->seenTimes + 1;
        nameFound = 1;
        break;
      }
    }
    
    if (nameFound == 0)
    {
      c->countArray = realloc(c->countArray, (c->arrayLength + 1) * sizeof(*(c->countArray)));
      one_count_t * one_count = malloc(sizeof(*one_count));
      one_count->seenTimes = 1;
      one_count->n = malloc(strlen(name)+1);
      strcpy(one_count->n, name);  
      c->countArray[c->arrayLength] = one_count;
      c->arrayLength +=1;
    }
  }


}
void printCounts(counts_t * c, FILE * outFile) {
  for (int i = 0; i < c->arrayLength; i++)
  {
    fprintf(outFile, "%s: %ld\n" ,c->countArray[i]->n, c->countArray[i]->seenTimes);
  }
  if (c->countUnknownNames > 0)
    fprintf(outFile, "<unknown> : %ld\n" , c->countUnknownNames);
}

void freeCounts(counts_t * c) {
  for (int i = 0; i < c->arrayLength; i++)
  {
    free(c->countArray[i]->n);
    free(c->countArray[i]);
  }
  free(c->countArray);
  free(c);
}
