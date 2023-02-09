#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  FILE * f = fopen(filename, "r");
  if (f == NULL)
  {
    perror("Could not open the file\n");
    return NULL;
  }

  counts_t * counts = createCounts();
  char * value = NULL;
  char * line = NULL;
  size_t sz = 0;
  while((getline(&line, &sz, f)>=0))
  {
    
    char *n = strchr(line,'\n');
    
    if(n != NULL){
      *n = '\0';}
    value = lookupValue(kvPairs, line);
    addCount(counts, value);
  }
  free(line);
  if(fclose(f)!=0)
  {
    perror("Error closing the file\n");
    return NULL;
  }
  
  return counts;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc<2)
  {
    fprintf(stderr, "Not enough arguments!\n");
    return EXIT_FAILURE;
  }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv_arr = readKVs(argv[1]);
  if (kv_arr == NULL)
  {
    fprintf(stderr, "Error reading the file!\n");
    return EXIT_FAILURE;
  }
 //count from 2 to argc (call the number you count i)
  for (int i = 2; i<argc; i++)
  {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv_arr);
    if(c == NULL) {return EXIT_FAILURE;}
    //compute the output file name from argv[i] (call this outName)
    char* outName = computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");
    //print the counts from c into the FILE f
    printCounts(c,f);
    //close f
    if (fclose(f)!=0)
    {
      perror("error closing the file!\n");
      return EXIT_FAILURE;
    }
    //free the memory for outName and c    
    freeCounts(c);
    free(outName);

  }

  freeKVs(kv_arr);


 //free the memory for kv

  return EXIT_SUCCESS;
}
